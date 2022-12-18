from rest_framework import generics, permissions,status
from rest_framework.response import Response
from rest_framework.request import Request
from .serializers import ProductSerializer
from .models import Produto
# Create your views here.
class ProductsAPI(generics.GenericAPIView):
    serializer_class = ProductSerializer
    # o Certo seria IsAuthenticatedOrReadOnly
    permission_classes = (permissions.AllowAny,)
    queryset=Produto.objects.all()
    
    def post(self, request: Request, *args, **kwargs):
        serializer: ProductSerializer = self.get_serializer(data=request.data)
        serializer.is_valid(raise_exception=True)
        serializer.save()
        return Response({"msg":"carrinho atualizado" },status=status.HTTP_201_CREATED)
      
    
    def get(self,request: Request,*args,**kwargs):
        order = request.query_params.get("sort") 
        if order in ['name', 'price', 'score']:
            serializer = ProductSerializer(self.get_queryset().order_by(order).values(), many=True)
        else: serializer = ProductSerializer(self.get_queryset(), many=True)

        return Response(serializer.data)
    
    
        