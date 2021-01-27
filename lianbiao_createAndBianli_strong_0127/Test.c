#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
//用结构体模拟每一节点
typedef struct Node {
	int data;//数据域
	struct Node* pNext;//指针域
}NODE, * PNODE;
//链表的创建与遍历
PNODE create_list();
void traverse_list(PNODE pHead);
int main() {
	PNODE pHead = NULL;//头指针

	pHead = create_list();//功能就是创建一个非循环单链表,并将该链表的头结点的地址(首地址)付给pHead
	traverse_list(pHead);
	return 0;
}
PNODE create_list() {//实现函数:链表创建
	int len;//用来存放有效节点的个数
	int i;//循环控制变量i

	//创建了一个头结点,pHead不是头结点,但是pHead指向的动态内存是头结点,不存放任何有效数,pHead也就是头指针
	PNODE pHead = (PNODE)malloc(sizeof(NODE));//临时节点
	if (NULL == pHead) {
		printf("内存分配失败,程序终止\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;


	printf("请输入您想要创建的链表节点的个数:len = ");
	scanf("%d", &len);
	for (i = 0; i < len; i++) {
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew) {
			printf("内存分配失败,程序终止\n");
			exit(-1);
		}
		printf("请输入第%d个节点的值:", i + 1);
		scanf("%d", &(pNew->data));

		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;

}
void traverse_list(PNODE pHead) {//实现函数:链表遍历
	PNODE pNext1;
	pNext1 = pHead->pNext;
	while (pNext1 != NULL) {
		printf("%d\n", pNext1->data);
		pNext1 = pNext1->pNext;
	}
	printf("\n");
	return;
}