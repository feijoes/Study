from django.db import models

# Create your models here.
class Produto(models.Model):
    name = models.CharField(max_length=40,primary_key=True)
    price = models.FloatField()
    score = models.IntegerField()
    image = models.CharField(max_length=100)
    
    def __str__(self) -> str:
        return self.name
    
