#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
#define error -1
#define queue_size 6
#define elem_type char

typedef struct queue{
	unsigned int length;
	unsigned int tail,head;
	elem_type elem[queue_size];
}queue;

int init(queue &q);
int enqueue(queue &q,elem_type e);
int dequeue(queue &q,elem_type &e);
int queue_empty(queue q);
int queue_full(queue q);
int print_queue(queue q);



int init(queue &q){
	q.head=q.tail=1;
	q.length=0;
	return 1;
}
int enqueue(queue &q,elem_type e){
	if(queue_full(q))
		return 0;
	else {
		q.elem[q.tail]=e;
		q.tail+=1;
		if(q.tail==queue_size)
			q.tail=0;
		q.length+=1;
		return 1;
	}
}
int dequeue(queue &q,elem_type &e){
	if(queue_empty(q))
		return 0;
	e=q.elem[q.head];
	q.head+=1;
	if(q.head==queue_size)
		q.head=0;
	q.length-=1;
	return 1;
}
int queue_empty(queue q){
	if(q.tail==q.head )
		return 1;
	else return 0;
}
int queue_full(queue q){
	if(q.head==q.tail+1)
		return 1;
	else return 0;
}

int print_queue(queue q){
	while(q.head!=q.tail){
		cout<<q.elem[q.head]<<' ';
		q.head+=1;
		if(q.head==queue_size)
			q.head=0;
	}
	return 1;
}

int main(){
	queue q;
	elem_type e;
	init(q);
	cout <<"将abcde入队列"<<endl;
	enqueue(q,'a');
	enqueue(q,'b');
	enqueue(q,'c');
	enqueue(q,'d');
	enqueue(q,'e');
	print_queue(q);
	cout<<endl;
	cout<<"两次出队列"<<endl;
 	dequeue(q,e);
	dequeue(q,e);
	print_queue(q);cout<<endl;
	return 1;
}
