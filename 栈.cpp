#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

#define Stack_Init_Size 100
#define StackIncrement 10
typedef int SElemType;

typedef struct{
	SElemType *top;
	SElemType *base;
	int stacksize;
}SqStack;

int InitStack(SqStack &s){
	//栈的初始化
	s.base = (SElemType *)malloc(Stack_Init_Size * sizeof(SElemType));
	if (!s.base) exit(-1);	//存储分配失败
	s.top = s.base;
	return 1;
}

int GetTop(SqStack s, SElemType &e){
	//获取栈顶元素
	if (s.base == s.top) return -1;		//栈为空
	e = *(s.top - 1);
	return 1;
}

int Push(SqStack &s, SElemType e){
	//插入元素e
	if (s.top - s.base >= s.stacksize){
		s.base = (int *)realloc(s.base, (s.stacksize + StackIncrement) * sizeof(int));
		if (!s.base) exit(-1);	//存储分配失败
		s.top = s.base + StackIncrement;
		s.stacksize += StackIncrement;
	}
	*s.top++ = e;
	return 1;
}

int Pop(SqStack &s, SElemType &e){
	//删除栈顶元素
	if (s.base == s.top) return -1;		//栈为空
	e = *--s.top;
	return 1;
}

void printStack(SqStack s){
	if (s.base == s.top) printf("栈为空！\n");
	int *t = s.base;
	printf("当前栈的元素为：\n");
	while(t < s.top){
		printf("%d ", *t);
		t++;
	}
	printf("\n");
}

int main(){
	SqStack s;
	InitStack(s);
	int e;
	for(int i = 1; i <= 10; i++)
		Push(s, i);
	printStack(s);
	printf("删除栈顶元素----\n");
	Pop(s, e);
	printStack(s);
	return 0;
}
