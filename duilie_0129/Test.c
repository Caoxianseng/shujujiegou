#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* pNext;
}*PNODE,NODE;
typedef struct Queue {
	PNODE pHead;
	PNODE pTail;
}*PQUEUE, QUEUE;

void Queue(PQUEUE pS) {
	pS->pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pHead) {
		printf("内存分配失败\n");
		exit(-1);
	}
	pS->pTail = pS->pHead;
	pS->pHead->pNext  = NULL;
	return;
}


void InQueue(PQUEUE pS,int val) {

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = NULL;
	pS->pTail->pNext = pNew;//将pNew挂到队列尾部
	pS->pTail = pNew;//将尾指针上移
}


int isEmpty(PQUEUE pS) {
	if (pS->pHead == pS->pTail)
		return 1;
	else
		return 0;
}

void OutQueue(PQUEUE pS) {
	if (isEmpty(pS))
		printf("队列为空,不能出队\n");
	else {
		PNODE pTemp = pS->pHead->pNext;
		pS->pHead->pNext = pTemp->pNext;
		int val = pTemp->data;
		free(pTemp);
		pTemp = NULL;
		if (NULL == pS->pHead->pNext) {//队列为空的时候,就是尾指针也被删除了,就需要将尾指针也指向一个位置
			pS->pTail = pS->pHead;//就是这个位置
		}
		printf("出队成功,出队元素为:%d\n", val);
	}
}

void Travers(PQUEUE pS) {
	PNODE pTemp = pS->pHead->pNext;
	while (pTemp != NULL) {
		printf("%d\t", pTemp->data);
		pTemp = pTemp->pNext;
	}
	printf("\n");
}


void clearQueue(PQUEUE pS) {
	while (!isEmpty(pS)) {
		PNODE pTemp = pS->pHead->pNext;
		free(pS->pHead);
		pS->pHead = NULL;
		pS->pHead = pTemp;
		pTemp->pNext = pS->pHead->pNext ;
	}
	free(pS->pHead);
	pS->pHead = NULL;
	free(pS->pTail);
	pS->pTail = NULL;
}


int main() {
	QUEUE queue;
	Queue(&queue);
	Travers(&queue);
	InQueue(&queue, 1);
	InQueue(&queue, 2);
	InQueue(&queue, 3);
	InQueue(&queue, 4);
	InQueue(&queue, 5);
	InQueue(&queue, 6);
	Travers(&queue);
	OutQueue(&queue);
	Travers(&queue);
	OutQueue(&queue);
	Travers(&queue);
	OutQueue(&queue);
	Travers(&queue);
	clearQueue(&queue);
	Travers(&queue);
	return 0;
}
