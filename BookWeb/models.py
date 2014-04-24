from django.conf import settings
from django.contrib.auth.models import AbstractBaseUser, BaseUserManager, User
from django.db import models

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
    seller = models.ForeignKey(User)
    def __str__(self):
        return "%s: %s" % (self.author, self.title)
