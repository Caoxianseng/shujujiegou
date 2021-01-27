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
int main() {
	PNODE pHead = NULL;//ͷָ��

	pHead = create_list();//���ܾ��Ǵ���һ����ѭ��������,�����������ͷ���ĵ�ַ(�׵�ַ)����pHead
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
		printf("%d\n", pNext1->data);
		pNext1 = pNext1->pNext;
	}
	printf("\n");
	return;
}