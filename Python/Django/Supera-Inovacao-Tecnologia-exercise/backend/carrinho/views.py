
from rest_framework import generics, permissions,status
from rest_framework.permissions import IsAuthenticated
from .serializers import CarrinhoSerializer
from rest_framework.response import Response
from rest_framework.request import Request
from .models import Carrinho

class Template(generics.GenericAPIView):
    permission_classes = [IsAuthenticated]

    def perform_create(self, serializer):
        """Criar um objeto"""
        serializer.save()


class CarrinhoAPI(Template):
    """Usar os Pedidos da base de dados"""
    queryset = Carrinho.objects.all()
    serializer_class = CarrinhoSerializer

    def get_queryset(self):
        """retornar o objectos autenticados"""

        return self.queryset.get(user=self.request.user)
    
    def get(self,request: Request):
       
        return Response(self.get_serializer(self.get_queryset()).data)
    
    def post(self,request: Request):
        serializer: CarrinhoSerializer = self.get_serializer(data=request.data)
        serializer.is_valid(raise_exception=True)
        serializer.save()
        
        return Response(serializer.data)
        
    