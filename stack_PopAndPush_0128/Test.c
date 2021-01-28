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
	PNODE pTop;//����,ָ��ָ�����Ӷ���,���Ҫɾ��һ��Ԫ��,�ͽ�pTop������һ��λ��,��ͷ��
	PNODE  pBottom;//�ײ�,ָ��ָ�����ӵײ�,һ��ֵ����,��β��
}STACK,* PSTACK;

void initStack(PSTACK pS) {//��ջ���г�ʼ��
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pTop) {
		printf("��̬�ڴ����ʧ��,�����˳�\n");
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
		printf("��̬�ڴ����ʧ��,�����˳�\n");
		exit(-1);
	}
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
}

//����һ����������ʵ���ж�ջ�Ƿ�Ϊ��
int empt(PSTACK pS) {
	if (pS->pBottom == pS->pTop)
		return 1;//˵����ʱ����Ϊ��,����Ԫ��Ϊ1
	else
		return 0;
}

int popStack(PSTACK pS, int* val) {//�з���ֵ����,��Ϊ��������ջ��
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
void traverse(PSTACK pS) {//������ʱ�򲻿��Ըı�ջ�Ľṹ
	PNODE p = pS->pTop;
	while (p != pS->pBottom) {
		printf("%d\t", p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}

void clearStack(PSTACK pS) {//����һ����������ʵ�ֽ�ջ���,����ǽ���������ݽ���ɾ��,���ǿ�ܻ���
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
	initStack(&S);//���һ����ջ
	pushStack(&S,1);//ѹջ
	pushStack(&S,2);//ѹջ
	pushStack(&S,3);
	pushStack(&S,9);
	pushStack(&S,95);
	pushStack(&S,64);
	pushStack(&S,924);
	traverse(&S);//�������
	if (popStack(&S, &val)) {
		printf("��ջ�ɹ�,����ֵΪ:%d\n", val);
	}
	else {
		printf("��ջʧ��\n");
	}
	if (popStack(&S, &val)) {
		printf("��ջ�ɹ�,����ֵΪ:%d\n", val);
	}
	else {
		printf("��ջʧ��\n");
	}
	traverse(&S);
	clearStack(&S);
	if (popStack(&S, &val)) {
		printf("��ջ�ɹ�,����ֵΪ:%d\n", val);
	}
	else {
		printf("��ջʧ��\n");
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
