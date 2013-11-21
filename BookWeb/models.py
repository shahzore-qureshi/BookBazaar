from django.db import models

# Create your models here.

class Course(models.Model):
    subject = models.CharField(max_length=4)
    number = models.IntegerField()

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
    
class Person(models.Model):
	firstname = models.CharField(max_length=20)
	lastname = models.CharField(max_length=20)
	email = models.EmailField([max_length=75, **options])
	
class BookSellers(models.Model):
    seller = models.ForeignKey(Person)
    bookid = models.ForeignKey(Book)
