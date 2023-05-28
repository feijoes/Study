from rest_framework.serializers import ModelSerializer, SerializerMethodField, CharField, ListField, ValidationError
from django.contrib.auth import get_user_model
from core.models import Menu, Prato

from copy import copy


class PratoSerializer(ModelSerializer):
    """Serializador do Prato"""

    class Meta:
        model = Prato
        fields = '__all__'


class MenuSerializer(ModelSerializer):
    """Serializador do Menu"""
    pratos = SerializerMethodField('get_pratos')
    user = SerializerMethodField('get_user')
    nomes_prato = ListField(child=CharField(write_only=True), write_only=True)


    class Meta:
        model = Menu
        fields = ('nome', 'user', 'pratos', 'nomes_prato')

    def create(self, validated_data):
        """Criar um Menu"""
        pratos = validated_data.pop('nomes_prato', None)

        validated_data['user'] = get_user_model().objects.get(email=self.context['request'].user)

        instance = super().create(validated_data)
        try:
            instance.pratos.set(set(Prato.objects.get(nome=i) for i in pratos))
        except Exception:
            raise ValidationError({"detail": "Prato nao existe"})
        return instance

    def update(self, instance, validated_data):
        """ Update and return Menu instance """
        pratos = validated_data.pop("nomes_prato") if 'nomes_prato' in validated_data else []
        menu = Menu.objects.get(nome=instance.nome)
        instance.nome = validated_data.get('nome', instance.nome)
        if pratos:
            try:
                for i in pratos:
                    obj = Prato.objects.get(nome=i)
                    menu.pratos.add(obj)

            except Exception:
                raise ValidationError({"detail": "Prato nao existe"})
        pr = copy(menu.pratos.all())
        menu.delete()
        new = Menu.objects.create(nome=instance.nome, user=self.context['request'].user)
        for i in pr:
            new.pratos.add(i)
        return new

    @staticmethod
    def get_user(obj):
        """Ver o user"""
        return obj.user.email
    @staticmethod
    def get_pratos(obj):
        """ver os Pratos do menu"""
        return [PratoSerializer(prato).data for prato in obj.pratos.all()]


