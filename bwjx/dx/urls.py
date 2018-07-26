from django.conf.urls import url
from . import views
from django.views.generic.base import RedirectView
app_name = 'dx'

urlpatterns = [
    url(r'^$',views.test,name='test'),
    url(r'^test1/$', views.test1, name='test1'),
]