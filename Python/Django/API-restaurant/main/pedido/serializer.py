from django.contrib.auth import get_user_model
from rest_framework.serializers import ModelSerializer, SerializerMethodField, CharField, DictField, ValidationError
from core.models import Pedido, Cliente, Prato, Count
from menu.serializer import PratoSerializer
import asyncio
class ClienteSerializer(ModelSerializer):
    """Serializador do Pedido"""
    Customer = SerializerMethodField('get_customer_name')
    customer_name = CharField(write_only=True)
    pratos = SerializerMethodField('get_pratos')
    valor_total = SerializerMethodField('get_valor_total')
    nomes_prato = DictField(child=CharField(write_only=True), write_only=True)

    class Meta:
        model = Pedido
        fields = ('Customer', 'customer_name', 'pratos', "valor_total", 'nomes_prato')

    def update(self, instance, validated_data):
        """ Update and return Pedido """
        pratos = validated_data.pop("nomes_prato") if 'nomes_prato' in validated_data else []
        customer_name = validated_data.pop('customer_name', self.get_customer_name(instance))
        try:
            for prato in pratos.keys():
                for i in range(int(pratos[prato])):
                    Count.objects.create(prato=Prato.objects.get(nome=prato), pedido=instance.pedido)
        except Exception:
            raise ValidationError({"detail": "Prato nao existe"})
        return instance

    def create(self, validated_data):
        """Criar um Pedido"""
        pratos = validated_data.pop('nomes_prato', None)
        customer_name = validated_data.pop('customer_name', None)
        instance = super().create(validated_data)
        try:
            for prato in pratos.keys():
                for i in range(int(pratos[prato])):
                    Count.objects.create(prato=Prato.objects.get(nome=prato), pedido=instance)
        except Exception:
            raise ValidationError({"detail": "Prato nao existe"})
        Cliente.objects.create(customer_name=customer_name,
                               user=get_user_model().objects.get(email=self.context['request'].user),
                               pedido=instance)
        return instance

    @staticmethod
    def get_pratos(obj):
        """ver os Pratos do menu"""
        try:
            return [PratoSerializer(prato).data for prato in obj.pedido.pratos.all()]
        except Exception:
            pass

    @staticmethod
    def get_valor_total(obj):
        try:
            return obj.pedido.valor_total
        except Exception:
            pass

    @staticmethod
    def get_customer_name(obj):
        try:
            return f'{Cliente.objects.get(pedido=obj.pedido)}'
        except Exception:
            pass



