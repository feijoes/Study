from django.contrib import admin
from django.contrib.auth.admin import UserAdmin as Base
from .models import *
from django.utils.translation import gettext as _


class UserAdmin(Base):
    ordering = ['email']
    list_display = ['email']
    fieldsets = (
        (None, {'fields': ('email', 'password')}),

        (
            _('Permissions'),
            {'fields': ('is_active', 'is_staff', 'is_superuser')}
        ),
        (_('Important dates'), {'fields': ('last_login',)})
    )

    add_fieldsets = (
        (None, {
            'classes': ('wide',),
            'fields': ('email', 'password1', 'password2'),
        }),
    )


admin.site.register(User, UserAdmin)
admin.site.register(Prato)
admin.site.register(Menu)
admin.site.register(Pedido)
admin.site.register(Cliente)
admin.site.register(Count)
