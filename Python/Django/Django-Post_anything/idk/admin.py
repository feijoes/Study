from django.contrib import admin
from .models import Post
from django.contrib.auth.models import Group


class PostAdmin(admin.ModelAdmin):
    list_display = ('title', 'date')
    list_filter = ['date']


admin.site.site_header = "Admin page"
admin.site.register(Post,PostAdmin)
admin.site.unregister(Group)