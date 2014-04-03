from django.conf.urls import patterns, include, url

# Uncomment the next two lines to enable the admin:
# from django.contrib import admin
# admin.autodiscover()

urlpatterns = patterns('',
    # Examples:
    url(r'^$', 'BookWeb.views.home', name='home'),
    url(r'^create_user$', 'BookWeb.views.create_user', name='create_user'),
    url(r'^login$', 'BookWeb.views.login', name='login'), 
    url(r'^logout$', 'BookWeb.views.logout', name='logout'), 
    # url(r'^css/', include) 

    # url(r'^BookBazaar/', include('BookBazaar.foo.urls')),

    # Uncomment the admin/doc line below to enable admin documentation:
    # url(r'^admin/doc/', include('django.contrib.admindocs.urls')),

    # Uncomment the next line to enable the admin:
    # url(r'^admin/', include(admin.site.urls)),
)
