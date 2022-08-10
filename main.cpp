#include <iostream>
#include <time.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

using namespace std;

class SqStack {
private:
	ElemType *base;
	ElemType *top;
	int stacksize;
public:
	SqStack() {}

	void InitStack() {
		base = new ElemType[MAXSIZE];
		if (!base) cout << "OVERFLOW" << endl;
		top = base;
		stacksize = MAXSIZE;
	}

	void Push(ElemType e) {
		if (top - base != MAXSIZE) 
			*top++ = e;
	}

	void Pop(ElemType &e) {
		if (top == base)
			cout << "ERROR" << endl;
		e = *--top;
	}

	ElemType GetTop() {
		if (top == base)
			return ERROR;
		return *(top - 1);
	}

	void Print() {
		ElemType *tmp = top;
		while (tmp != base)
		{
			cout << *(tmp - 1) << endl;
			tmp--;
		}
	}
};

typedef struct StackNode {

	ElemType data;
	StackNode* next;
}StackNode, *LinkStack;

Status InitStack(LinkStack &S) {
	S = nullptr;
	return OK;
}

Status Push(LinkStack &S, ElemType e) {
	StackNode* newNode = new StackNode;
	newNode->data = e;
	newNode->next = S;
	S = newNode;
	return OK;
}

Status Pop(LinkStack &S, ElemType &e) {
	if(!S) return ERROR;
	e = S->data;
	StackNode* p;
	p = S;
	S = S->next;
	delete p;
	return OK;
}

ElemType GetTop(LinkStack S) {
	if(S) return S->data;
}

void PrintStack(LinkStack S) {
	StackNode *p = S;
	while (p)
	{
		cout << p->data <<"  ";
		p = p->next;
	}
	cout << endl;
	
}

int main(int argc, char *argv[])
{
	#if 0
	int e;
	SqStack S;
	S.InitStack();
	S.Push(5);	
	S.Push(4);
	S.Push(3);
	S.Push(2);
	S.Push(1);
	S.Print();
	S.Pop(e);
	S.Pop(e);
	cout << e << endl;
	cout << S.GetTop() << endl;
	#endif

	#if 0
	LinkStack S;
	InitStack(S);
	for (int i = 0; i < 6; i++) {
		Push(S, i);
	}
	PrintStack(S);
	int a;
	Pop(S, a);
	PrintStack(S);
	cout << GetTop(S) << endl;
	#endif
}