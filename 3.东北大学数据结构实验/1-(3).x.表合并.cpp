#include<iostream>
using namespace std;
struct Node
{
    int value;
    Node* next;
    Node(int v):value(v){}
};
/*创建一个链表，1->2->3->4->5->6->7*/
Node* CreateList1()//创建一个有序的单链表1
{
   Node *head;
   Node *n1=new Node(1);
   Node *n3=new Node(3);
   Node *n5=new Node(5);
   Node *n7=new Node(7);
   Node *n9=new Node(9);
   head=n1;
   n1->next=n3;
   n3->next=n5;
   n5->next=n7;
   n7->next=n9;
   n9->next=NULL;
   return head;
}
Node* CreateList2()//创建一个有序的单链表2
{
   Node *head;
   Node *n2=new Node(2);
   Node *n4=new Node(4);
   Node *n6=new Node(6);
   Node *n8=new Node(8);
   head=n2;
   n2->next=n4;
   n4->next=n6;
   n6->next=n8;
   n8->next=NULL;
   return head;
}
void FreeList(Node *head)//将链表空间释放
{
    if(head==NULL)
    {
        return ;
    }
    else
    {
        Node *temp=head->next;
        delete head;
        head=temp;
        FreeList(head);
    }
}

void VisitList(Node *head)//遍历链表中的元素,用递归的方法遍历
{
    if(head)
    {
        cout<<head->value<<"->";
        VisitList(head->next);
    }
    else
    {
        cout<<"null"<<endl;
    }
}
Node *ListMerge(Node *head1,Node *head2)
{
    if(!head1) return head2;
    if(!head2) return head1;
    Node *head=NULL;//合并后的头指针
    Node *p1=head1;//p1用于扫描链表1
    Node *p2=head2;//p2用于扫描链表2
    if(head1->value<head2->value)
    {
        head=head1;
        p1=head1->next;
    }
    else
    {
        head=head2;
        p2=head2->next;
    }
    Node *p=head;//p永远指向最新合并的结点
    while(p1 && p2)//如果循环停止，则p1或p2至少有一个为NULL
    {
        if(p1->value<p2->value)
        {
            p->next=p1;
            p1=p1->next;
        }
        else
        {
            p->next=p2;
            p2=p2->next;
        }
        p=p->next;
    }
    if(p1)//如果链1还没走完
    {
        p->next=p1;
    }
    else if(p2)//如果链2还没走完
    {
        p->next=p2;
    }
    return head;
}

Node *ListMerge1(Node *head1,Node *head2)//采用递归的方法实现
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    Node *head=NULL;
    if(head1->value < head2->value)
    {
        head=head1;
        head->next=ListMerge1(head1->next,head2);
    }
    else
    {
        head=head2;
        head->next=ListMerge1(head1,head2->next);
    }
    return head;
}
int main()
{
    Node *head1=CreateList1();
    Node *head2=CreateList2();
    cout<<"合并前"<<endl;
    cout<<"链表1:";
    VisitList(head1);
    cout<<"链表2:";
    VisitList(head2);
    cout<<"合并后的链表:";
    //Node *head=ListMerge(head1,head2);
    Node *head=ListMerge1(head1,head2);
    VisitList(head);
    FreeList(head);
    return 0;
}

