# -*- coding: UTF-8 -*-
import os
path=r"C:\Users\26696\Desktop\BaiduImageSpider-master\xhc"
i=0
for file in os.listdir(path):
    if os.path.isfile(os.path.join(path,file))==True:
        os.rename(os.path.join(path,file),os.path.join(path,"xhc"+str(i)+".jpg"))
        i=i+1