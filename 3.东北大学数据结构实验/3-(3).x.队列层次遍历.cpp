    #include<iostream>
    #include<malloc.h>
    #define LEN sizeof(BiTree)
    #define MAXQSIZE   100;         //���г���
    using namespace std;
    struct BiTree                           //������
    {
        char data;
        BiTree *lchild,*rchild;
    }*T;
    struct Qnode        //������
    {
        BiTree *Queue[100];   //M��ʾѭ��ָ����еĳ���
         int nfront,nrear;        //ͷ��β  ���ڴ�����������int�Ϳ���
    }head;
    BiTree* CreatBiTree()  //�������������������λ�ò�^
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
      {  BiTree *p;                                                                    // ����һ�� ������ָ��p
         Qnode Q;Q.nrear=Q.nfront=0;                                //��ʼ���������
          if (T!=NULL)
            {   Q.Queue[Q.nrear]=T;                                         //���T����
           Q.nrear=(Q.nrear+1)%MAXQSIZE;              //����һ��ββ��
            while (Q.nfront !=Q.nrear)                         //������ ���в���  Ҳ���Ƕ�����������
                {
                      p=Q.Queue[Q.nfront];                                        //p���ڶ���ͷ
           cout<<p->data;                                              //�������ͷ��
                     Q.nfront=(Q.nfront+1)%MAXQSIZE;           //front�����ƶ�һ��
                        if (p->lchild)                                                    //��������Ӳ���
                    { Q.Queue[Q.nrear]=p->lchild;                     //��ôβ����������
                    Q.nrear=(Q.nrear+1)%MAXQSIZE;                 //rear�����ƶ�һ��
                    }
                    if (p->rchild)                                              //Ȼ�����Һ���
                    {  Q.Queue[Q.nrear]=p->rchild;             //ͬ��
                    Q.nrear=(Q.nrear+1)%MAXQSIZE;
                    }
                }
            }
    }

    int main()                                                                   //���� ����
    {
        BiTree*test=CreatBiTree();
        Levelorder(test);
    return 0;
    }
