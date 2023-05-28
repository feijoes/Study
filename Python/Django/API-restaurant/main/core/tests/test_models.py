from django.test import TestCase
from django.contrib.auth import get_user_model
from .. import models


class ModelTestUser(TestCase):

    def test_create_with_user_email_successful(self):
        """" Provar Criar usuario com email corretamente"""

        email = 'test@gmail.com'
        password = 'SenhaTest123'
        user = get_user_model().objects.create_user(email, password=password)

        self.assertEqual(user.email, email)
        self.assertTrue(user.check_password(password))

    def test_create_with_user_email_fall(self):
        """Test criar usuario sem email"""
        with self.assertRaises(ValueError):
            get_user_model().objects.create_user(None, password='SenhaTest123')

    def test_new_user_email_normalize(self):
        """Test email para novo usuario normalizado"""

        email = 'test@GMAIL.COM'
        user = get_user_model().objects.create_user(email, password='SenhaTest123')

        self.assertEqual(user.email, email.lower())

    def test_create_superuser(self):
        """Test criando super usuario"""
        user = get_user_model().objects.create_superuser('test@gmail.com', password='SenhaTest123')

        self.assertTrue(user.is_staff)
        self.assertTrue(user.is_superuser)


class ModelTestModels(TestCase):

    def test_create_prato(self):
        """ Test criar Prato"""
        nome = "hamburguer simples"
        info = "Um simples hamburger com carne, cebola, alface e cheedar"
        valor = 10

        prato = models.Prato.objects.create(nome=nome, info=info, valor=valor)

        self.assertEqual(models.Prato.objects.get(nome=nome), prato)

    def test_create_Menu(self):
        """Test para criar um Menu"""
        nome = "Menu de almoco"
        user = get_user_model().objects.create_user("test@gmail.com", password='SenhaTest123')
        prato1 = models.Prato.objects.create(nome="hamburguer simples",
                                             info="Um simples hamburger com 150g de carne, cebola, alface e cheedar",
                                             valor=10)
        prato2 = models.Prato.objects.create(nome="hamburguer medio",
                                             info="Um mais completo com 200g de carne, cebola, alface , cheedar, pepino",
                                             valor=15)
        prato3 = models.Prato.objects.create(nome="hamburguer monstro",
                                             info="Um simples hamburger com 300g carne, cebola, alface e cheedar",
                                             valor=20)

        menu = models.Menu.objects.create(nome=nome,user=user)
        menu.pratos.set((prato1, prato2, prato3))

        self.assertEqual(models.Menu.objects.get(nome=nome), menu)

    def test_create_pedido(self):
        """test para crear pedido"""
        prato1 = models.Prato.objects.create(nome="hamburguer simples",
                                             info="Um simples hamburger com 150g de carne, cebola, alface e cheedar",
                                             valor=10)
        prato2 = models.Prato.objects.create(nome="hamburguer medio",
                                             info="Um mais completo com 200g de carne, cebola, alface , cheedar, pepino",
                                             valor=15)
        pedido = models.Pedido.objects.create()
        models.Count.objects.create(prato=prato1, pedido=pedido)
        models.Count.objects.create(prato=prato1, pedido=pedido)
        models.Count.objects.create(prato=prato2, pedido=pedido)

        self.assertEqual(models.Pedido.objects.get(id=pedido.id), pedido)
        self.assertEqual(pedido.valor_total, 35)


