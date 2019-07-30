#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

//采用C++写法,创建链表时默认创建0号结点，也就是头结点.头结点指向的第一个结点为1号结点
struct LNode{
	int data;	
	LNode *next;	
	LNode(int x) : data(x), next(NULL) {} 
	//结构体构造函数，用这种方式初始化更方便,new代替了malloc函数
};

LNode *CreateNode(void){
	//LNode *Head = (LNode *)malloc(sizeof(LNode));
	LNode *head = new LNode(0);		//0号结点相当于头结点
	LNode *p = head;
	LNode *node = NULL;
	int x;
	while(cin>>x){
		if (!x) break;	//输入0代表输入结束
		node = new LNode(x);
		p->next = node;
		p = node;
	}
	p->next = NULL;
	return head;
}

void printLNode(LNode *head){
	if (head->next == NULL){	//判断链表是否为空
		cout << "Your LNode is empty" << endl;
		return;
	}
	LNode *p = head->next;
	int i = 1;
	while(p){
		cout << "第" << i++ << "个元素为:" << p->data << endl;
		p = p->next;
	}
}

int getLength(LNode *head){
	int l = 0;
	LNode *p = head->next;
	while(p){
		p = p->next;
		l++;
	}
	return l;
}

int GetElem(LNode *L, int i, int &e){
	//当第i个元素存在时，把它的值赋给e
	LNode *p = L->next;	//初始化p指向第一个结点
	int j = 1;
	while(p && j < i){		//使p指向第i个结点或p为空
		p = p->next;
		j++;
	}
	if (!p || j >= i) return 0;		//第i个元素不存在
	e = p->data;
	return 1;
}

int ListInsert(LNode *head, int i, int e){
	//在带头结点的单链表中第i个位置之前插入元素e
	LNode *p = head;
	int j = 0;
	while(p && j < i - 1){	//找到第i - 1个结点
		p = p->next;
		j++;
	}
	if (!p || j >= i) return 0;	//i<1 或 i>表长+1
	LNode *s = new LNode(e);	//生成新结点
	s->next = p->next;
	p->next = s;
	return 1;
}

int ListDelete(LNode *head, int i, int &e){
	//在带头结点的单链表中删除第i位元素，并返回到e
	LNode *p = head;
	int j = 0;
	while(p && j < i - 1){	//找到第i-1个结点
		p = p->next;
		j++;
	}
	//cout << "j= " << j << endl;
	if (!p || j >= i) return 0;
	LNode *q = p->next;
	e = q->data;
	cout << e << endl;
	p->next = q->next;
	delete q;
	return 1;
}

int main(){
	LNode *head = CreateNode();
	cout << "输入的链表为：---------------" << endl;
	printLNode(head);
	cout << "-----------------------------" << endl;
	int l = getLength(head);
	cout << "链表的长度为" << l << endl;
	ListInsert(head, 9, 1000);
	cout << "-----------------------------" << endl;
	cout << "在第9个元素前插入1000后的链表：" << endl;
	cout << "链表长度为: " << getLength(head) << endl;
	printLNode(head);
	cout << "-----------------------------" << endl;
	int e, x;
	cout << "请输入要删除几号结点" << endl;
	cin >> x;
	ListDelete(head, x, e);
	cout << "删除后的链表为:" << endl;
	printLNode(head);
	return 0;
}
