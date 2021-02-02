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
		printf("�ڴ����ʧ��\n");
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
	pS->pTail->pNext = pNew;//��pNew�ҵ�����β��
	pS->pTail = pNew;//��βָ������
}


int isEmpty(PQUEUE pS) {
	if (pS->pHead == pS->pTail)
		return 1;
	else
		return 0;
}

void OutQueue(PQUEUE pS) {
	if (isEmpty(pS))
		printf("����Ϊ��,���ܳ���\n");
	else {
		PNODE pTemp = pS->pHead->pNext;
		pS->pHead->pNext = pTemp->pNext;
		int val = pTemp->data;
		free(pTemp);
		pTemp = NULL;
		if (NULL == pS->pHead->pNext) {//����Ϊ�յ�ʱ��,����βָ��Ҳ��ɾ����,����Ҫ��βָ��Ҳָ��һ��λ��
			pS->pTail = pS->pHead;//�������λ��
		}
		printf("���ӳɹ�,����Ԫ��Ϊ:%d\n", val);
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
