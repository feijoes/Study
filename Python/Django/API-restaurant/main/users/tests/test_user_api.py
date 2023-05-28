from django.test import TestCase
from django.contrib.auth import get_user_model
from django.urls import reverse

from rest_framework.test import APIClient
from rest_framework import status


CREATE_USER_URL = reverse('users:create')
ME_URL = reverse('users:me')


def Data():
    return {
        'email': 'test@gmail.com',
        'password': 'Senha123'
    }


class PublicUserApiTest(TestCase):
    """ Testar o API publico do usuario """

    def setUp(self):
        self.client = APIClient()

    def test_create_valid_user(self):
        """Test de criar usuario"""
        data = Data()
        res = self.client.post(CREATE_USER_URL, data)

        self.assertEqual(res.status_code, status.HTTP_201_CREATED)
        user = get_user_model().objects.get(**res.data)

        self.assertTrue(user.check_password(data['password']))
        # Ver se a senha nao esta a vista
        self.assertNotIn('password', res.data)

    def test_user_exists(self):
        """ Test para ver se criar um usuario que ja existe falha """

        data = Data()

        get_user_model().objects.create_user(**data)

        res = self.client.post(CREATE_USER_URL, data)
        self.assertEqual(res.status_code, status.HTTP_400_BAD_REQUEST)

    def test_retrieve_user_unauthorized(self):
        """ Test provar que a authenticacao seja requerida para os usuarios """

        res = self.client.get(ME_URL)

        self.assertEqual(res.status_code, status.HTTP_403_FORBIDDEN)


class PrivateUserApiTest(TestCase):
    """ Testar o API Privado do usuario """

    def setUp(self):
        self.client = APIClient()
        self.user = get_user_model().objects.create_user(**Data())
        self.client.force_authenticate(user=self.user)

    def test_retrieve_profile_success(self):
        """ Test obter perfil para usuario com login"""
        res = self.client.get(ME_URL)

        self.assertEqual(res.status_code, status.HTTP_200_OK)

        self.assertEqual(res.data, {'email': self.user.email})

    def test_post_me_not_allowed(self):
        """ Test para nao autorizar Post para atualizar"""
        res = self.client.post(ME_URL, {})

        self.assertEqual(res.status_code, status.HTTP_405_METHOD_NOT_ALLOWED)

    def test_update_user_profile(self):
        """Test para autorizar user"""
        data = {
            'email': 'novo@gmail.com',
            'password': 'novasenha'
        }

        res = self.client.patch(ME_URL, data)
        print()
        self.user.refresh_from_db()
        self.assertEqual(self.user.email, data['email'])
        self.assertTrue(self.user.check_password(data['password']))
        self.assertEqual(res.status_code, status.HTTP_200_OK)
