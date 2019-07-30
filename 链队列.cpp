#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;

/*
链队列设有一个头结点，并令头指针指向头结点。空的链队列判断条件为头指针和尾指
针均向头结点.
*/

typedef int ElemType;

typedef struct QNode{	
	ElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

//每个队列的元素都是一个QNode结点

typedef struct{
	QueuePtr front;	//队头指针
	QueuePtr rear;	//队尾指针
}LinkQueue;

int InitQueue(LinkQueue &q){
	//初始化一个空队列
	q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q.front) exit(-2);	//存储分配失败
	q.front->next = NULL;
	return 1;
}

int EnQueue(LinkQueue &q, ElemType e){
	//入队操作
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(-2);
	p->data = e;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	return 1;
}

int DeQueue(LinkQueue &q, ElemType &e){
	if (q.rear == q.front) return -1;	//队列为空
	QueuePtr p = q.front->next;		//令p指向队头结点
	q.front->next = p->next;
	e = p->data;
	if (q.rear == p) q.rear = q.front;	//若原队列中只有一个结点，删除后边空
	free(p);
	return 1;
}

void PrintQueue(LinkQueue q){
	QueuePtr p = q.front->next;
	int i = 0;
	while(p){
		printf("第%d个元素是:%d\n", ++i, p->data);
		p = p->next;
	}
}

int main(){
	LinkQueue q;
	InitQueue(q);
	int e;
	printf("---初始化队列---\n");
	printf("---开始给队列插入元素---\n");
	for(int i = 1; i < 11; i++)
		EnQueue(q, i);
	PrintQueue(q);
	printf("---删除队头元素---\n");
	DeQueue(q, e);
	PrintQueue(q);
	return 0;
}
