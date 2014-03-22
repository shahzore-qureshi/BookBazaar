from django.conf import settings
from django.contrib.auth.models import AbstractBaseUser, BaseUserManager
from django.db import models

# Create your models here.

# class PersonManager(BaseUserManager):
#    def create_user(self, email, password=None):
#        user = self.model(username=email.split("@")[0],
#                          email=email)
#        return user

#class Person(AbstractBaseUser):
#    username = models.CharField(max_length=20, unique=True)
#   firstname = models.CharField(max_length=20)
#    lastname = models.CharField(max_length=20)
#    email = models.EmailField()

 #   USERNAME_FIELD = 'username'
  #  REQUIRED_FIELDS = ['email']

#    def __str__(self):
#        return "%s %s (%s)" % (self.firstname, self.lastname, self.email)

class Course(models.Model):
    subject = models.CharField(max_length=4)
    number = models.IntegerField()
    def __str__(self):
        return "%s%i" % (self.subject, self.number)

class Book(models.Model):
    CONDITIONS = (
        ('N','NEW'),
        ('G','GOOD'),
        ('O','OKAY'),
        ('P','POOR'),
    )
    title = models.CharField(max_length=128)
    author = models.CharField(max_length = 128)
    isbn = models.CharField(max_length=10)
    condition = models.CharField(max_length=16, choices=CONDITIONS)
    price = models.DecimalField(max_digits=19, decimal_places=4)
    course = models.ForeignKey(Course)
    #seller = models.ForeignKey(settings.AUTH_USER_MODEL)
    def __str__(self):
        return "%s: %s" % (self.author, self.title)
