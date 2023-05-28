from django.urls import path, include
from rest_framework.routers import DefaultRouter
from .views import *
from pedido import views


router = DefaultRouter()

router.register('menu', MenuViewSet)
router.register('prato', PratoViewSet)
router.register('cliente', views.ClienteViewSet, basename='cliente')

app_name = 'menu'

urlpatterns = [
    path('', include(router.urls))]
