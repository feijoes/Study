
from .views import *
from django.urls import path

urlpatterns = [
    path('produtos/', ProductsAPI.as_view(), name='produtos'),
]