from rest_framework import serializers
from .models import Produto


class ProductSerializer(serializers.ModelSerializer):
    class Meta:
        model = Produto
        fields = ('name','price','score','image')
      

    def create(self, validated_data):
        print(validated_data)
        produto = Produto.objects.create(**validated_data)

        return produto