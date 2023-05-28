from django.shortcuts import render

from .form import PostForm
from django.urls import reverse
from django.http import HttpResponseRedirect
from .models import Post


def index(request):
    context = {'posts': Post.objects.all()}
    return render(request, "html/posts.html", context)


def contact(request):
    return render(request, "html/Contact.html")


def info(request):
    return render(request, "html/info.html")


def post(request):
    if request.method == 'POST':
        form = PostForm(request.POST)
        if form.is_valid():
            Post(title=form.cleaned_data['title'].capitalize(), body=form.cleaned_data['body']).save()
            return HttpResponseRedirect(reverse('index'))
        else:
            return render(request, "html/post.html", {'form': form})
    return render(request, "html/post.html", {'form': PostForm()})


def post_info(request, id):
    obj = Post.objects.get(id=id)
    return render(request, "html/zoom.html", {'title': obj.title, 'body': obj.body, 'date': obj.date})



