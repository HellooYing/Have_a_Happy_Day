    #include<iostream>
    #include<malloc.h>
    #define LEN sizeof(BiTree)
    #define MAXQSIZE   100;         //队列长度
    using namespace std;
    struct BiTree                           //二叉树
    {
        char data;
        BiTree *lchild,*rchild;
    }*T;
    struct Qnode        //链队列
    {
        BiTree *Queue[100];   //M表示循环指针队列的长度
         int nfront,nrear;        //头和尾  用于处理数组所以int就可以
    }head;
    BiTree* CreatBiTree()  //类似先序遍历创立，空位置补^
    {
        BiTree *T;
        char ch;cin>>ch;
        if(ch=='^')T=NULL;
        else{
            T=(BiTree *)malloc(LEN);
            T->data=ch;
            T->lchild=CreatBiTree();
            T->rchild=CreatBiTree();
         }
        return T;
    }
    void Levelorder(BiTree *T)
      {  BiTree *p;                                                                    // 建立一个 工作树指针p
         Qnode Q;Q.nrear=Q.nfront=0;                                //初始化这个队列
          if (T!=NULL)
            {   Q.Queue[Q.nrear]=T;                                         //如果T不空
           Q.nrear=(Q.nrear+1)%MAXQSIZE;              //加入一个尾尾部
            while (Q.nfront !=Q.nrear)                         //如果这个 队列不空  也就是二叉树不结束
                {
                      p=Q.Queue[Q.nfront];                                        //p等于队列头
           cout<<p->data;                                              //输出队列头部
                     Q.nfront=(Q.nfront+1)%MAXQSIZE;           //front往后移动一个
                        if (p->lchild)                                                    //如果做左孩子不空
                    { Q.Queue[Q.nrear]=p->lchild;                     //那么尾部加上左孩子
                    Q.nrear=(Q.nrear+1)%MAXQSIZE;                 //rear往后移动一个
                    }
                    if (p->rchild)                                              //然后是右孩子
                    {  Q.Queue[Q.nrear]=p->rchild;             //同上
                    Q.nrear=(Q.nrear+1)%MAXQSIZE;
                    }
                }
            }
    }

    int main()                                                                   //运行 结束
    {
        BiTree*test=CreatBiTree();
        Levelorder(test);
    return 0;
    }
