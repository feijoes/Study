from django.db import models
from django.contrib.auth.models import AbstractBaseUser, BaseUserManager, PermissionsMixin
from django.conf import settings
from django.db.models.signals import post_save, pre_save
from django.dispatch import receiver


class CustomUserManager(BaseUserManager):
    """
    Meu user model manager onde o email é o que identifica
    para autenticação.
    """
    def create_user(self, email, password, **extra_fields):
        """
        Cria e Salva User com email e password.
        """
        if not email:
            raise ValueError('The Email must be set')

        user = self.model(email=self.normalize_email(email), **extra_fields)
        user.set_password(password)
        user.save(using=self._db)

        return user

    def create_superuser(self, email, password, **extra_fields):
        """Criar SuperUser """

        user = self.create_user(email, password)
        user.is_superuser = True
        user.is_staff = True

        user.save(using=self._db)

        return user


class User(AbstractBaseUser, PermissionsMixin):
    """Modelo de usuario para fazer login com email. """

    email = models.EmailField(max_length=255, unique=True)

    is_active = models.BooleanField(default=True)
    is_staff = models.BooleanField(default=False)
    menus = models.ManyToOneRel
    objects = CustomUserManager()

    USERNAME_FIELD = 'email'

    def __str__(self):
        return self.email


class Prato(models.Model):
    """Modelo dos Pratos"""
    nome = models.CharField(max_length=255, unique=True, primary_key=True)
    info = models.CharField(max_length=255)
    valor = models.IntegerField()

    def __str__(self):
        return self.nome


class Menu(models.Model):
    """Modelo dos Menus"""
    nome = models.CharField(max_length=255, primary_key=True,  unique=True)
    user = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE)
    pratos = models.ManyToManyField(Prato, related_name='pratos', related_query_name='pratos')

    def __str__(self):
        return self.nome


class Pedido(models.Model):
    """Modelo do pedido"""
    pratos = models.ManyToManyField(Prato, related_name='pedido_pratos', related_query_name='pedido_pratos',through="Count")
    valor_total = models.IntegerField(default=0)

    def __str__(self):
        return f'{self.valor_total}'


class Cliente(models.Model):
    """Modelo do Cliente"""
    customer_name = models.CharField(max_length=255, primary_key=True,  unique=True)
    user = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE)
    pedido = models.OneToOneField(Pedido, on_delete=models.CASCADE, related_name="pedido",blank=True,null=True)

    def __str__(self):
        return self.customer_name

class Count(models.Model):
    prato = models.ForeignKey(Prato, on_delete=models.CASCADE)
    pedido = models.ForeignKey(Pedido, on_delete=models.CASCADE)

    def __str__(self):
        return f'{self.prato}'


"""
Toda vez que um objeto e adicionado pro pedido ele atualiza o valor total 
"""

@receiver(post_save, sender=Count)
def create_profile(sender, instance, created, **kwargs):
    if created:
        valor_total = 0
        for count in Count.objects.filter(pedido=instance.pedido):
            valor_total += count.prato.valor
        instance.pedido.valor_total = valor_total
        instance.pedido.save()










