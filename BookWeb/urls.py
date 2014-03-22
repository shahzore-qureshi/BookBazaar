from django.conf.urls import patterns, include, url

# Uncomment the next two lines to enable the admin:
# from django.contrib import admin
# admin.autodiscover()

urlpatterns = patterns('',
    # Examples:
    url(r'^$', 'BookWeb.views.test', name='test'),
    url(r'^acctinit$', 'BookWeb.views.acctinit', name='acctinit'),
    url(r'^acctinit_submit$', 'BookWeb.views.acctinit_submit', name='acctinit_submit'),
    url(r'^acct_login$', 'BookWeb.views.acct_login', name='acct_login') 

    # url(r'^BookBazaar/', include('BookBazaar.foo.urls')),

    # Uncomment the admin/doc line below to enable admin documentation:
    # url(r'^admin/doc/', include('django.contrib.admindocs.urls')),

    # Uncomment the next line to enable the admin:
    # url(r'^admin/', include(admin.site.urls)),
)
