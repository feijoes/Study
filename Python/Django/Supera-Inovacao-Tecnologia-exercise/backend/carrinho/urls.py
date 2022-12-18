
from .views import *
from django.urls import path

urlpatterns = [
    path('carrinho/', CarrinhoAPI.as_view(), name='carrinho'),
]