# Generated by Django 4.0.3 on 2022-12-17 19:47

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('products', '0001_initial'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='produto',
            name='id',
        ),
        migrations.AlterField(
            model_name='produto',
            name='name',
            field=models.CharField(max_length=40, primary_key=True, serialize=False),
        ),
    ]
