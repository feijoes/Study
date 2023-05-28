from django.urls import path
from .views import *


app_name = 'users'

urlpatterns = [
    path('create/', UserView.as_view(), name='create'),
    path('me/', ManagerUserView.as_view(), name='me'),


]