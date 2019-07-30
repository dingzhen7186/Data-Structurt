//1.循环队列
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;

/*
顺序存储结构中，设置front和rear指针指示队列头元素和队列尾元素的位置，初始化
队列时，令front=rear=0,没当插入新的元素时，尾指针+1，每当删除队列头元素时，
头指针+1。头指针始终指向队列头元素，尾指针指向对列尾元素的下一位置
*/

#define MAXQSIZE 100	//最大队列长度
typedef int ElemType;

typedef struct{
	ElemType *base;	//初始化动态分配存储空间
	int front;		//头指针，若队列不为空，指向队头元素
	int rear;		//尾指针，若队列不为空，指向队尾元素的下一位置
}SqQueue;

int InitQueue(SqQueue &q){
	q.base = (ElemType *)malloc(MAXQSIZE * sizeof(ElemType));
	if (!q.base) exit(-2);
	q.front = q.rear = 0;
	return 1;
}

int QueueLength(SqQueue q){
	return (q.rear - q.front + MAXQSIZE) % MAXQSIZE;
}

int EnQueue(SqQueue &q, ElemType e){
	if ((q.rear + 1) % MAXQSIZE == q.front) return -1;//队列满
	q.base[q.rear] = e;
	q.rear = (q.rear + 1) % MAXQSIZE;
	return 1;
}

int DeQueue(SqQueue &q, ElemType &e){
	if (q.rear == q.front) return -1;	//队列为空
	e = q.base[q.front];
	q.front = (q.front + 1) % MAXQSIZE;
	return 1;
}

void PrintQueue(SqQueue q){
	ElemType p = q.front;
	int i = 0;
	//队尾指针指向的是队尾元素的下一位置，所以q.rear-1 指向的才是队尾元素
	while(p < q.rear){
		printf("第%d个元素为%d\n", ++i, q.base[p]);
		p++;
	}
}

int main(){
	SqQueue s;
	InitQueue(s);
	printf("---初始化队列---\n");
	printf("---插入元素进队列---\n");
	for(int i = 1; i < 11; i++)
		EnQueue(s, i);
	PrintQueue(s);
	int e;
	DeQueue(s, e);
	printf("---删除队头元素---\n");
	PrintQueue(s);
	return 0;
}

//2.单链队列
/*
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
*/

