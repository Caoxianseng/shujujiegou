#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef struct Node {
	int data;
	struct Node* pNext;
}NODE,* PNODE;

typedef struct Stack {
	PNODE pTop;//顶端,指针指向箱子顶部,如果要删除一个元素,就将pTop向下移一个位置,在头部
	PNODE  pBottom;//底部,指针指向箱子底部,一般值不变,在尾部
}STACK,* PSTACK;

void initStack(PSTACK pS) {//对栈进行初始化
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pTop) {
		printf("动态内存分配失败,程序退出\n");
		exit(-1);
	}
	else {
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL;
	}
}
void pushStack(PSTACK pS,int val) {
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew) {
		printf("动态内存分配失败,程序退出\n");
		exit(-1);
	}
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
}

//定义一个函数用来实现判断栈是否为空
int empt(PSTACK pS) {
	if (pS->pBottom == pS->pTop)
		return 1;//说明此时就是为空,返回元素为1
	else
		return 0;
}

int popStack(PSTACK pS, int* val) {//有返回值类型,因为可能面临栈空
	if (empt(pS)) {
		return 0;
	}
	else {
		PNODE p = pS->pTop;
		*val = pS->pTop->data;
		pS->pTop = pS->pTop->pNext;
		free(p);
		p = NULL;
		return 1;
	}
}
void traverse(PSTACK pS) {//遍历的时候不可以改变栈的结构
	PNODE p = pS->pTop;
	while (p != pS->pBottom) {
		printf("%d\t", p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}

void clearStack(PSTACK pS) {//定义一个行数用来实现将栈清空,清空是将里面的数据进行删除,但是框架还在
	if (empt(pS)) {
		return;
	}
	PNODE p = pS->pTop;
	PNODE q = NULL;
	while (p != pS->pBottom) {
		q = p->pNext;
		free(p);
		p = q;
	}
	pS->pTop = pS->pBottom;
}

int main() {
	STACK S;
	int val;
	initStack(&S);//造出一个空栈
	pushStack(&S,1);//压栈
	pushStack(&S,2);//压栈
	pushStack(&S,3);
	pushStack(&S,9);
	pushStack(&S,95);
	pushStack(&S,64);
	pushStack(&S,924);
	traverse(&S);//遍历输出
	if (popStack(&S, &val)) {
		printf("出栈成功,弹出值为:%d\n", val);
	}
	else {
		printf("出栈失败\n");
	}
	if (popStack(&S, &val)) {
		printf("出栈成功,弹出值为:%d\n", val);
	}
	else {
		printf("出栈失败\n");
	}
	traverse(&S);
	clearStack(&S);
	if (popStack(&S, &val)) {
		printf("出栈成功,弹出值为:%d\n", val);
	}
	else {
		printf("出栈失败\n");
	}
	traverse(&S);
	pushStack(&S, 3);
	pushStack(&S, 9);
	pushStack(&S, 95);
	pushStack(&S, 64);
	pushStack(&S, 924);
	traverse(&S);
	
	return 0;
}
