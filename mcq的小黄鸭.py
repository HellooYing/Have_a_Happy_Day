import random
import os
l=["对，然后呢？","好像是这样的","对对对对对对对","要不……试试女装？","这么晚了，睡觉吧，身体重要","emmmmm……我也不知道","你在丢人","哇！","似乎没什么问题？","来局文明5？","前面没哪错了吗","现在的思路是清晰的吧","给dalao递茶","我觉得不行","让你摸鱼，让你摸鱼","没毛病，就是这样！","啥玩意啊","咋回事啊","老子绝b是对的啊","挺好挺好","哇，巨TM给","我觉得你凉了","要不来局吃鸡吧","加油"]

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

