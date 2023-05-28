from rest_framework import viewsets, mixins
from rest_framework.permissions import IsAuthenticated
from . import serializer
from core.models import Menu , Prato

from users import serializers as s



class Temprate(mixins.CreateModelMixin,mixins.RetrieveModelMixin,mixins.UpdateModelMixin,mixins.DestroyModelMixin,mixins.ListModelMixin,viewsets.GenericViewSet):
    permission_classes = [IsAuthenticated]

    def perform_create(self, serializer):
        """Criar um objeto"""
        serializer.save()


class MenuViewSet(Temprate):
    """Usar os menus da base de dados"""
    queryset = Menu.objects.all()
    serializer_class = serializer.MenuSerializer


    def get_queryset(self):
        """retornar o objectos autenticados"""
        return self.queryset.filter(user=self.request.user)


class PratoViewSet(Temprate):
    """Usar os menus da base de dados"""

    queryset = Prato.objects.all()
    serializer_class = serializer.PratoSerializer

