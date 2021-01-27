#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
//�ýṹ��ģ��ÿһ�ڵ�
typedef struct Node {
	int data;//������
	struct Node* pNext;//ָ����
}NODE, * PNODE;
//����Ĵ��������




PNODE create_list();
void traverse_list(PNODE pHead);
int  if_empty(PNODE pHead);
int length_list(PNODE pHead);
void sort_list(PNODE pHead);
int insert_list(PNODE pHead, int pos, int val);
int delete_list(PNODE pHead, int pos, int* val);


int main() {
	PNODE pHead = NULL;//ͷָ��
	int pos = 0;
	int val;

	pHead = create_list();//���ܾ��Ǵ���һ����ѭ��������,�����������ͷ���ĵ�ַ(�׵�ַ)����pHead
	traverse_list(pHead);

	if (if_empty(pHead))
		printf("������Ϊ��\n");
	else
		printf("����Ϊ��\n");

	int len = length_list(pHead);
	printf("������ĳ���Ϊ:%d\n", len);

	sort_list(pHead);
	traverse_list(pHead);
	insert_list(pHead, 4, 33);
	traverse_list(pHead);
	printf("��������Ҫɾ����λ��:");
	scanf("%d", &pos);
	if (delete_list(pHead, pos, &val))
		printf("ɾ���ɹ�,ɾ����Ԫ�ص�Ϊ:%d\n", val);
	else
		printf("ɾ��ʧ��\n");
	traverse_list(pHead);
	return 0;
}


PNODE create_list() {//ʵ�ֺ���:������
	int len;//���������Ч�ڵ�ĸ���
	int i;//ѭ�����Ʊ���i

	//������һ��ͷ���,pHead����ͷ���,����pHeadָ��Ķ�̬�ڴ���ͷ���,������κ���Ч��,pHeadҲ����ͷָ��
	PNODE pHead = (PNODE)malloc(sizeof(NODE));//��ʱ�ڵ�
	if (NULL == pHead) {
		printf("�ڴ����ʧ��,������ֹ\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;


	printf("����������Ҫ����������ڵ�ĸ���:len = ");
	scanf("%d", &len);
	for (i = 0; i < len; i++) {
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew) {
			printf("�ڴ����ʧ��,������ֹ\n");
			exit(-1);
		}
		printf("�������%d���ڵ��ֵ:", i + 1);
		scanf("%d", &(pNew->data));

		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;

}




void traverse_list(PNODE pHead) {//ʵ�ֺ���:�������
	PNODE pNext1;
	pNext1 = pHead->pNext;
	while (pNext1 != NULL) {
		printf("%d\t", pNext1->data);
		pNext1 = pNext1->pNext;
	}
	printf("\n");
	return;
}



//����һ����������ʵ�ֶ���������п�
int  if_empty(PNODE pHead) {
	if (pHead->pNext == NULL)
		return 1;//˵������Ϊ��,����1
	else
		return 0;
}

//����һ������ʵ��������ĳ���
int length_list(PNODE pHead) {
	if (if_empty(pHead)) {
		return 0;
	}
	int len = 0;
	PNODE p = pHead->pNext;
	while (NULL != p)
	{
		len++;
		p = p->pNext;
	}
	return len;
}



//����һ������ʵ�ֶ�������Ĳ���
//������ĵ�pos���ڵ��ǰ�����һ�����µĽ��,�ýڵ��ֵΪval,����pos��ֵ��1��ʼ
int insert_list(PNODE pHead, int pos, int val) {
	int i = 0;
	PNODE p = pHead;
	while (NULL != p && i < pos - 1) {
		p = p->pNext;
		++i;
	}

	if (i > pos - 1 || NULL == p)
		return 0;

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew) {
		printf("��̬�ڴ����ʧ��\n");
		exit(-1);
	}
	pNew->data = val;
	// PNODE q = p->pNext;
	// p->pNext = pNew;
	// pNew->pNext = q;
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	return 1;
}




//����һ������ʵ��ɾ��Ԫ��
int delete_list(PNODE pHead, int pos,int* val) {//�������������ǽ�ɾ���Ĳ����������
	int i = 0;
	PNODE p = pHead;


	while (NULL != p->pNext && i < pos - 1) {
		p = p->pNext;
		++i;
	}
	if (i > pos - 1 || NULL == p->pNext)
		return 0;

	PNODE q = p->pNext;
	*val = q->data;
	//ɾ��p�ڵ����Ľڵ�
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return 1;
}

//����һ������ʵ�ֶ������������
void sort_list(PNODE pHead) {
	int i = 0;
	int j = 0;
	int temp = 0;
	int len = 0;
	len = length_list(pHead);
	PNODE p ,q;
	for (i = 0, p = pHead->pNext; i < len - 1; ++i, p = p->pNext) {
		for (j = i + 1,q = p->pNext; j < len; j++,q = q->pNext) {
			if (p->data > q->data) {
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
	}
	return;
}
