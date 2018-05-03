import random
import os
l=["对，然后呢？","好像是这样的","似乎没什么问题？","前面没哪错了吗","现在的思路是清晰的吧","挺好挺好","会是什么问题呢？","我觉得这个bug快被解决了","一定是这样的","加油"]

def out(l):
    i=random.randint(0,len(l)-1)
    print(l[i])

print("这次叫什么名字呢？")
p=input()
q=1
fp = open(p+".txt","w") 
while q==1:
    p=input()
    fp.write(p)
    fp.write('\n')
    if p=='0':
        fp.close()
        q=0
    else:
        out(l)

