# Create your views here.
from django.http import HttpResponse
from django.shortcuts import render
from django.contrib.auth.models import User
from django.contrib.auth import authenticate, login as auth_login, logout as auth_logout
import logging

def home(request):
    if request.user.is_authenticated():
      return render(request, "html/home.html", {})
    else:
      return login(request)

def create_user(request):
    if request.method == 'POST':
      user = User.objects.create_user(request.POST["username"], request.POST["email"], request.POST["password"])
      user.save()
      return login(request)
    elif request.method == 'GET':
      return render(request, "html/create_user.html", {})

def login(request):
    if request.method == 'POST':
      user = authenticate(username=request.POST["username"], password=request.POST["password"])
      status = 'failed'
      if user is not None:
        # the password verified for the user
        if user.is_active:
          print("User is valid, active and authenticated")
          status = 'valid'
          auth_login(request, user)
          return home(request)
        else:
          print("The password is valid, but the account has been disabled!")
          status = 'disabled'
      else:
        # the authentication system was unable to verify the username and password
        status = 'failed'
      return render(request, "html/login.html", {'status':status})
    elif request.method == 'GET':
      return render(request, "html/login.html", {'status':''})

def logout(request):
    auth_logout(request)
    return home(request)
