from rest_framework import generics
from rest_framework.permissions import IsAuthenticated
from .serializers import UserSerializer
from rest_framework.authtoken.views import ObtainAuthToken
from rest_framework.settings import api_settings


class UserView(generics.CreateAPIView):
    """Criar um novo usuario"""
    serializer_class = UserSerializer


class ManagerUserView(generics.RetrieveUpdateAPIView):
    """Lidar com o usuario autenticado"""
    serializer_class = UserSerializer
    permission_classes = [IsAuthenticated]

    def get_object(self):
        return self.request.user

class UserloginApiView(ObtainAuthToken):
    """Area de login"""
    renderer_classes = api_settings.DEFAULT_RENDERER_CLASSES
