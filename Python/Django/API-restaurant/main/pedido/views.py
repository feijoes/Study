
from rest_framework import viewsets, mixins
from rest_framework.permissions import IsAuthenticated
from . import serializer
from core.models import Prato, Pedido, Cliente


class Temprate(mixins.CreateModelMixin,mixins.RetrieveModelMixin,mixins.UpdateModelMixin,mixins.DestroyModelMixin,mixins.ListModelMixin,viewsets.GenericViewSet):
    permission_classes = [IsAuthenticated]

    def perform_create(self, serializer):
        """Criar um objeto"""
        serializer.save()


class ClienteViewSet(Temprate):
    """Usar os Pedidos da base de dados"""
    queryset = Cliente.objects.all()
    serializer_class = serializer.ClienteSerializer

    def get_queryset(self):
        """retornar o objectos autenticados"""
        return self.queryset.filter(user=self.request.user)