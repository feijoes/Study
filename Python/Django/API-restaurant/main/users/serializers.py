from django.contrib.auth import get_user_model
from rest_framework import serializers
from rest_framework.response import Response


class UserSerializer(serializers.ModelSerializer):
    """Serializadores para o Users"""

    class Meta:
        model = get_user_model()
        fields = ('email', 'password')
        extra_kwargs = {
            'password': {'write_only': True}
        }

    def create(self, validated_data):
        """Criar um novo usuario"""
        return get_user_model().objects.create_user(**validated_data)

    def update(self, instance, validated_data):
        """Atualizar nova senha de um usuario"""

        user = super().update(instance, validated_data)
        senha = validated_data.pop('password')
        user.set_password(senha)
        user.save()
        return user




