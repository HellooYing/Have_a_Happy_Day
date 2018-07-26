from django.shortcuts import render
from django.http import HttpResponse
import os
import json
from jpype import *
import shutil
def test(request):
    return render(request, 'test.html', context={})

def test1(request):
    a=[]
    c=[]
    d=[]
    jarpath = os.path.join(os.path.abspath('.'), 'C:/code/MCQ_Blog/')
    if not isJVMStarted():  
        startJVM("C:/Program Files/Java/jdk1.8.0_171/jre/bin/server/jvm.dll", "-ea", "-Djava.class.path=%s" % (jarpath + 'haha.jar'))  
    jd = JPackage("main").haha() 
    a=jd.find(request.GET.get("shuru"))
    b=str(a)[1:-1].replace("\n","").split(",")
    i=0
    while(i<len(b)):
        c.append(str(jd.split(a.get(i))))
        i=i+1
    i=0
    while(i<len(b)):
        e=[]
        e.append(b[i])
        e.append(c[0][1:-1].split(","))
        d.append(e)
        i=i+1
    print(d)
    return_json = {'d':d}
    #shutdownJVM() 
    return HttpResponse(json.dumps(return_json), content_type='application/json')

# Create your views here.
