from django.test import TestCase
from django.contrib.auth import get_user_model

from rest_framework.test import APIClient
from rest_framework import status
from menu.tests.test_api import Data
from core.models import *
from ..serializer import ClienteSerializer

TAGS_URL = "http://127.0.0.1:8000/api/cliente/"


class PublicPedidoApiTest(TestCase):
    """Provar os Pedidos desde modo anonimo """

    def setUP(self):
        self.client = APIClient()

    def test_login_required(self):
        """Test lista de todos os menus"""
        res = self.client.get(TAGS_URL)
        self.assertEqual(res.status_code, status.HTTP_403_FORBIDDEN)


class PrivateUserApiTest(TestCase):
    """ Testar o API Privado do usuario """

    def setUp(self):
        self.client = APIClient()
        self.user = get_user_model().objects.create_user(**Data())
        self.client.force_authenticate(user=self.user)
        self.prato = Prato.objects.create(nome="hamburguer simples",
                                          info="Um simples hamburger com 150g de carne, cebola, alface e cheedar",
                                          valor=10)

    def test_retrieve_pedidos_success(self):
        """ Test obter os pedidos"""
        res = self.client.get(TAGS_URL)
        self.assertEqual(res.status_code, status.HTTP_200_OK)

    def test_criar_pedido(self):
        """Test para criar os pedidos"""
        data = {
            "customer_name": "Pedro",
            "nomes_prato": {"hamburguer simples": 2}
        }

        res = self.client.post(TAGS_URL, data, format="json")

        exists = Cliente.objects.filter(customer_name=data["customer_name"])

        self.assertEqual(res.status_code, status.HTTP_201_CREATED)
        self.assertTrue(exists.exists())

    def test_checar_valor(self):
        """test para ver se o valor total confere"""

        data = {
            "customer_name": "Pedro",
            "nomes_prato": {"hamburguer simples": 3}
        }

        self.client.post(TAGS_URL, data, format="json")

        self.assertEqual(self.client.get(TAGS_URL).data[0]["valor_total"], 30)

    def test_adicionar_prato_pro_pedido(self):
        """Test para adiconar mais um prato no Pedido"""
        data = {
            "nomes_prato": {"hamburguer simples": 3}
        }
        self.client.post(TAGS_URL, {
            "customer_name": "Pedro",
            "nomes_prato": {"hamburguer simples": 3}
        }, format="json")

        res = self.client.patch(TAGS_URL+"Pedro/", data, format="json")
        self.assertEqual(self.client.get(TAGS_URL).data[0]["valor_total"], 60)



