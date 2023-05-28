from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('contact', views.contact, name='contact'),
    path("info", views.info, name="info"),
    path("post", views.post, name="post"),
    path('<int:id>', views.post_info, name='zoom')
]
