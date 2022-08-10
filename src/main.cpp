#include <iostream>
#include <time.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

using namespace std;

typedef struct 
{
	ElemType *elem;
	int length;
}SqList;

Status InitList(SqList &L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)	exit(OVERFLOW);
	L.length = 0;
	return OK;
}

Status ListAssign(SqList &L, int n) {
	srand(time(0));
	for (int i = 0; i < n; ++i) {
		L.elem[i] = rand() % 100;
	}
	L.length = n;
	return OK;
}

Status GetElem(SqList &L, int i, ElemType &e) {
	if (i < 1 || i > L.length)	return ERROR;
	e = L.elem[i - 1];
	return OK;
}

int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; ++i)
		if (L.elem[i] == e)	return i + 1;
	return 0;
}

Status ListInsert(SqList &L, int i, ElemType e) {
	if (i < 0 || i > L.length + 1)	return ERROR;
	if (L.length == MAXSIZE)	return ERROR;
	for (int j = L.length - 1; j >= i - 1; --j)
		L.elem[j + 1] = L.elem[j];
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}

Status ListDelete(SqList &L, int i) {
	if(i < 0 || i > L.length)	return ERROR;
	for (int j = i; j <= L.length - 1; ++j)
		L.elem[j - 1] = L.elem[j];
	--L.length;
	return OK;
}

Status ListPrint(SqList L) {
	for (int i = 0; i < L.length; ++i)
		cout << L.elem[i] << "  ";
	cout << endl;
	return OK;
}



int main(int argc, char *argv[])
{
	int val, loc;
	SqList L;
	InitList(L);
	ListAssign(L,5);
	ListPrint(L);
	GetElem(L, 1, val);
	cout << val << endl;
	loc = LocateElem(L, 50);
	cout << loc << endl;
	ListInsert(L, 3, 25);
	ListPrint(L);
	ListDelete(L, 2);
	ListPrint(L);

}