from django import forms


class PostForm(forms.Form):
    title = forms.CharField(widget=forms.TextInput(attrs={'class': 'form-control', 'id':'title_form'}))
    body = forms.CharField(widget=forms.Textarea(attrs={'class': 'form-control', 'id':'title_form'}))
