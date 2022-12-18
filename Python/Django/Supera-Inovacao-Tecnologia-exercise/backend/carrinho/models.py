# Create your models here.
from django.db import models
from django.contrib.auth.models import User
from django.db.models.signals import post_save
from django.dispatch import receiver
from products.models import Produto
class Carrinho(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE)
    produtos =models.ManyToManyField(Produto, related_name='produto_carrinho', related_query_name='produtos_carrinhos',through="Count",blank=True,)
    
    def __str__(self) -> str:
        return f"{self.user} carrinho"


class Count(models.Model):
    carrinho = models.ForeignKey(Carrinho, on_delete=models.CASCADE)
    produto = models.ForeignKey(Produto, on_delete=models.CASCADE)

    def __str__(self):
        return f'{self.produto}'

@receiver(post_save, sender=User)
def create_user_carrinho(sender, instance, created, **kwargs):
    if created:
        Carrinho.objects.create(user=instance)

@receiver(post_save, sender=User)
def save_user_carrinho(sender, instance, **kwargs):
    instance.carrinho.save()