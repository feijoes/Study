from django.test import TestCase
from django.contrib.auth import get_user_model
from django.urls import reverse

from rest_framework.test import APIClient
from rest_framework import status

from core.models import *

from ..serializer import MenuSerializer, PratoSerializer


def Data():
    return {
        'email': 'test@gmail.com',
        'password': 'Senha123'
    }


TAGS_URL = reverse('menu:menu-list')
PRATO_URL = reverse('menu:prato-list')


class PublicMenusApiTest(TestCase):
    """Provar os Menus desde modo anonimo """

    def setUP(self):
        self.client = APIClient()

    def test_login_required(self):
        """Test lista de todos os menus"""
        res = self.client.get(TAGS_URL)
        self.assertEqual(res.status_code, status.HTTP_403_FORBIDDEN)




class PrivateMenusApiTest(TestCase):
    """Provar os Menus que estao disponiveis particularmente"""

    def setUp(self):
        self.client = APIClient()
        self.user = get_user_model().objects.create_user(**Data())
        self.client.force_authenticate(user=self.user)
        self.prato = Prato.objects.create(nome="hamburguer simples",
                                          info="Um simples hamburger com 150g de carne, cebola, alface e cheedar",
                                          valor=10)

    def test_retrieve_menus(self):
        """ Test ver menus"""
        menu = Menu.objects.create(nome="menu test", user=self.user)
        menu2 = Menu.objects.create(nome="menu teste2", user=self.user)
        menu.pratos.add(self.prato)
        menu2.pratos.add(self.prato)
        res = self.client.get(TAGS_URL)
        menus = Menu.objects.all()
        serializer = MenuSerializer(menus, many=True)

        self.assertEqual(res.status_code, status.HTTP_200_OK)
        self.assertEqual(res.data, serializer.data)

    def test_menus_limited_to_user(self):
        """Test para ver se os Menus retornados sejan do usuario"""

        user2 = get_user_model().objects.create_user('outro@gmail.com', 'senha123O')

        menu2 = Menu.objects.create(nome="menu test outro usuario", user=user2)
        menu2.pratos.add(self.prato)

        menu = Menu.objects.create(nome="menu test", user=self.user)
        menu.pratos.add(self.prato)

        res = self.client.get(TAGS_URL)

        self.assertEqual(res.status_code, status.HTTP_200_OK)
        self.assertEqual(len(res.data), 1)
        self.assertEqual(res.data[0]['nome'], menu.nome)

    def test_create_menu_successful(self):
        """Test para criar Menus"""
        Prato.objects.create(nome="coca",
                             info="Coca cola zero 1l",
                             valor=8)
        Prato.objects.create(nome="hamburguer",
                             info="Um mais completo com 200g de carne, cebola, alface , cheedar, pepino",
                             valor=10)
        Prato.objects.create(nome="batata",
                             info="Uma batata assada",
                             valor=15)

        data ={
            "nome": "Menu test",
            "nomes_prato": ["coca", "hamburguer", "batata"]
        }
        self.client.post(TAGS_URL, data)
        exists = Menu.objects.filter(nome=data['nome'], user=self.user)
        self.assertTrue(exists.exists())

    def test_create_menu_with_no_name(self):
        """Test criar um menu com um nome invalido"""
        data = {
            'nome': '',
            'nomes_prato': []
        }
        res = self.client.post(TAGS_URL, data)

        self.assertEqual(res.status_code, status.HTTP_400_BAD_REQUEST)

    def test_create_invalid_menu_with_invalid_prato(self):
        """Test criar um menu usando um prato que nao existe"""
        data = {
            'nome': 'menu test',
            'nomes_prato': ['um item que nao existe']
        }
        res = self.client.post(TAGS_URL, data)

        self.assertEqual(res.status_code, status.HTTP_400_BAD_REQUEST)

    def test_update_menu(self):
        """test para atualizar um menu"""
        Prato.objects.create(nome="coca",info="Coca cola zero 1l",valor=8)
        data = {
            "nome": "MenuTest",
        }
        newdata = {
            "nome": "outronome",
            "nomes_prato": ["coca"]
        }
        menu = Menu.objects.create(nome=data["nome"], user=self.user)
        menu.pratos.add(self.prato)

        res = self.client.patch("http://127.0.0.1:8000/api/menu/MenuTest/", newdata)
        self.assertEqual(res.status_code, status.HTTP_200_OK)
        self.assertTrue(Menu.objects.get(nome=newdata["nome"]))
        self.assertEqual(f'{Menu.objects.get(nome=newdata["nome"]).pratos.all()}', f'{Prato.objects.all().order_by("nome")}')

    def test_create_prato(self):
        """test para criar um prato"""
        data = {
            'nome': 'Test',
            'info': 'info test',
            'valor': 10
        }
        self.client.post(PRATO_URL,data)

        exists = Prato.objects.filter(nome=data['nome']).exists()
        self.assertTrue(exists)

    def test_get_pratos(self):
        """test para ver os pratos"""
        from core.models import Prato
        Prato.objects.create(nome="coca", info="Coca cola zero 1l", valor=8)
        Prato.objects.create(nome="hamburguer", info="Um mais completo com 200g de carne, cebola, alface , cheedar, pepino", valor=10)
        Prato.objects.create(nome="batata", info="Uma batata assada", valor=15)
        res = self.client.get(PRATO_URL)
        Prato = Prato.objects.all()
        serializer = PratoSerializer(Prato, many=True)

        self.assertEqual(res.status_code, status.HTTP_200_OK)
        self.assertEqual(res.data, serializer.data)



