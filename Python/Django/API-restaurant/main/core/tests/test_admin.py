from django.test import TestCase, Client
from django.contrib.auth import get_user_model
from django.urls import reverse



class AdminSiteTests(TestCase):

    def setUp(self):
        """ Adicionar um client, Superuser e test user"""
        self.client = Client()
        self.admin_user = get_user_model().objects.create_superuser(email='admin@gmail.com',password='Senha123')
        self.client.force_login(self.admin_user)
        self.user = get_user_model().objects.create_user(email='test@gmail.com',password='Senha123',)

    def test_users_listed(self):
        """Test se usuarios estao listados"""
        url = reverse('admin:core_user_changelist')
        res = self.client.get(url)

        self.assertContains(res, self.user.email)

    def test_user_change_page(self):
        """Test editar usuario"""
        url = reverse('admin:core_user_change', args=[self.user.id])
        res = self.client.get(url)

        self.assertEqual(res.status_code, 200)

    def test_create_user_page(self):
        """Test criar usuario"""
        url = reverse('admin:core_user_add')
        res = self.client.get(url)

        self.assertEqual(res.status_code, 200)