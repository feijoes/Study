from rest_framework.serializers import Serializer,SerializerMethodField, CharField, DictField, ValidationError
from .models import *
from products.serializers import ProductSerializer

class CarrinhoSerializer(Serializer):
    """Serializador do Carrinho"""

    produtos = SerializerMethodField('get_produtos')
    
    frete = SerializerMethodField('get_valor_frete')
    subtotal = SerializerMethodField('get_valor_subtotal')
    nomesProdutos = DictField(child=CharField(write_only=True), write_only=True)
    

    class Meta:
        model = Carrinho
        fields = ("nomesProdutos","produtos" ,"frete" ,"subtotal")


    def create(self, validated_data):
      
        produtos = validated_data.pop('nomesProdutos', {})
        instance = Carrinho.objects.get(user=self.context["request"].user)
        try:
            for produto in produtos.keys():
                produto = Produto.objects.get(name=produto)
                if int(produtos[produto.name]) > 0:
                    for _ in range(int(produtos[produto.name])):
                        Count.objects.create(produto=produto, carrinho=instance)
                    instance.produtos.add(produto)
                if int(produtos[produto.name]) < 0:
                    for _ in range(abs(int(produtos[produto.name]))):
                        Count.objects.filter(produto=produto, carrinho=instance)[0].delete()
                    
                instance.save()
        except Exception as e:
            print(e)
            raise ValidationError({"detail": "Produto nao existe"})

        return instance

    @staticmethod
    def get_produtos(obj):
        """ver os Produtos do carrinho"""
        try:
            return [{"produto":ProductSerializer(produto).data, "quantidade": len(obj.produtos.filter(name=produto.name))} for produto in set(obj.produtos.all())]
        except Exception as e:
            print(e)
            pass

    @staticmethod
    def get_valor_subtotal(obj):
        subtotal = 0
        for count in Count.objects.all().filter(carrinho=obj):
            subtotal += count.produto.price
        return subtotal

    @staticmethod
    def get_valor_frete(obj):
        if CarrinhoSerializer.get_valor_subtotal(obj) >= 250:
            return 0
        return len(Count.objects.all().filter(carrinho=obj)) * 10

   
