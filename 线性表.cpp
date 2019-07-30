#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

#define List_Init_Size 100 //线性表存储空间的初始分配量
#define ListIncrement 10   //线性表存储空间的分配增量

typedef struct{
	int *elem;		//存储空间基址
	int length; //当前表长
	int listsize;	//当前分配的存储大小
}SqList;

int InitList(SqList &L){
	//初始化一个空的线性表
	L.elem = (int *)malloc(List_Init_Size * sizeof(int)); //初始分配存储空间
	if (!L.elem) exit(-2);	//分配失败
	L.length = 0;
	L.listsize = List_Init_Size;
	return 1;
}

int DestroyList(SqList &L){
	//销毁线性表
	free(L.elem);	//直接释放掉这段空间
	return 1;
}

int ListEmpty(SqList L){
	//判断表是否为空
	if (L.length == 0) return 1;
	return 0;
}

/* 个人感觉这个实在没啥用
int ListLength(SqList L){
	//返回表长
	return L.length;
}
*/

int ListClear(SqList &L){
	//清空线性表
	for(int i = 0; i < L.length; i++)
		L.elem[i] = 0;
	L.length = 0;
	return 1;
}

int GetElem(SqList L, int i, int &e){
	//找到第i个元素，并用e返回
	if (i < 0 || i > L.length) return 0;	//i不合法
	e = L.elem[i - 1];
	return 1;
}

int LocateElem(SqList L, int e){
	//返回线性表中第一个和e相等的元素
	for(int i = 0; i < L.length; i++)
		if (L.elem[i] == e)
			return i + 1;
	return 0;
}

int PriorElem(SqList L, int cur, int &pre){
	//若cur是L中的元素，且不是第一个，则返回它的前驱
	for(int i = 0; i < L.length; i++){
		if (L.elem[i] == cur){
			if (i == 0){
				return 0;	//不能是第一个元素
			}
			pre = L.elem[i - 1];
			return 1;
		}
	}
	return 0;	//cur不在线性表中,找不到前驱
}

int NextElem(SqList L, int cur, int &next){
	//若cur是L中的元素，且不是最后一个，则返回它的后继
	for(int i = 0; i < L.length; i++){
		if (L.elem[i] == cur){
			if (i == L.length - 1){
				return 0;	//不能是最后一个元素
			}
			next = L.elem[i + 1];
			return 1;
		}
	}
	return 0;	//cur不是线性表中的元素
}

int ListInsert(SqList &L, int i, int e){
	//在第i个位置之前插入新的元素e
	if (i < 1 || i > L.length + 1) return 0;  //i不合法
	if (L.length >= L.listsize){	//当前空间已满，增加分配
		L.elem = (int *)realloc(L.elem, (L.listsize + ListIncrement) * sizeof(int));
		L.length += ListIncrement; 
	}
	int *q = &(L.elem[i-1]);
	int *p ;
	for(p = &(L.elem[L.length - 1]); p >= q; p--)
		*(p+1) = *p;	//插入的位置及以后的元素全部后移1位
	*q = e;
	L.length += 1;	//插入后表长+1
	return 1;
}

int ListDelete(SqList &L, int i, int &e){
	//删除第i位元素，并用e返回
	if (i < 1 || i > L.length) return 0;
	int *p = &(L.elem[i - 1]);
	e = *p;
	int *q = &(L.elem[L.length - 1]);
	for(++p; p <= q; p++){
		*(p - 1) = *p;
	}
	L.length--;
	return 1;
}

int main(){
	SqList s;
	printf("开始初始化线性表s\n");
	InitList(s);
	printf("空表长度: %d, 分配存储大小: %d\n",s.length,s.listsize);
	printf("---------------------------------\n");
	printf("开始进行插入操作\n");
	for(int i = 1; i <= 10; i++){
		printf("线性表第%d个元素插入%d\n",i,i);
		ListInsert(s, i, i);
	}
	printf("---------------------------------\n");
	if (ListEmpty(s)) printf("线性表为空\n");
	else printf("此时线性表的表长为: %d\n", s.length);
	int e;
	GetElem(s, 5, e);
	printf("第5个元素的值是: %d\n", e);
	printf("---------------------------------\n");
	PriorElem(s, 7, e);
	printf("第7个元素的前驱是: %d\n", e);
	NextElem(s, 7, e);
	printf("第7个元素的后继是: %d\n", e);
	printf("---------------------------------\n");
	ListDelete(s, 1, e);
	printf("删除1号元素后的表长: %d\n", s.length);
	for(int i = 0; i < s.length; i++){
		printf("第%d个元素为:%d\n", i + 1, s.elem[i]);
	}
	printf("---------------------------------\n");
	ListClear(s);
	printf("清空后s的表长: %d\n", s.length);
	DestroyList(s);
	return 0;
}
