#include <iostream>
#include <time.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

using namespace std;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

Status InitList(LinkList &L) {
	L = new LNode;
	L->next = nullptr;
	return OK;
}

Status GetElem(LinkList L, int i, ElemType &e) {
	LNode *p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)	return ERROR;
	e = p->data;
	return OK;
}

LNode *LocateElem(LinkList L, ElemType e) {
	LNode *p = L->next;
	while (p && p->data != e)
	{
		p = p->next;
	}
	return p;
}

Status ListInsert(LinkList &L, int i, ElemType e) {
	LNode *p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)	return ERROR;
	LNode *s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete(LinkList &L, int i) {
	LNode *p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	LNode *q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}

void CreateList_H(LinkList &L, int n) {
	L = new LNode;
	L->next = nullptr;
	for (int i = 0; i < n; ++i) {
		LNode *p = new LNode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

void CreateList_T(LinkList &L, int n) {
	L = new LNode;
	L->next = nullptr;
	LNode *r = L;
	for (int i = 0; i < n; ++i) {
		LNode *p = new LNode;
		cin >> p->data;
		p->next = r->next;
		r->next = p;
		r = p;
	}
}

void PrintList(LinkList L) {
	LNode *p = L->next;
	while (p)
	{
		cout << p->data << "  ";
		p = p->next;
	}
	cout << endl;
}

int main(int argc, char *argv[])
{
	int val;
	LinkList L;
	InitList(L);
	CreateList_H(L, 5);
	PrintList(L);
	GetElem(L, 2, val);
	cout << val << endl;
	ListInsert(L, 2, 35);
	PrintList(L);
	ListDelete(L, 4);
	PrintList(L);

	return 0;
}
