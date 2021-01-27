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
int  if_empty(PNODE pHead);
int length_list(PNODE pHead);
void sort_list(PNODE pHead);
int insert_list(PNODE pHead, int pos, int val);
int delete_list(PNODE pHead, int pos, int* val);


int main() {
	PNODE pHead = NULL;//头指针
	int pos = 0;
	int val;

	pHead = create_list();//功能就是创建一个非循环单链表,并将该链表的头结点的地址(首地址)付给pHead
	traverse_list(pHead);

	if (if_empty(pHead))
		printf("该链表为空\n");
	else
		printf("链表不为空\n");

	int len = length_list(pHead);
	printf("该链表的长度为:%d\n", len);

	sort_list(pHead);
	traverse_list(pHead);
	insert_list(pHead, 4, 33);
	traverse_list(pHead);
	printf("输入您想要删除的位置:");
	scanf("%d", &pos);
	if (delete_list(pHead, pos, &val))
		printf("删除成功,删除的元素的为:%d\n", val);
	else
		printf("删除失败\n");
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
		printf("%d\t", pNext1->data);
		pNext1 = pNext1->pNext;
	}
	printf("\n");
	return;
}



//创建一个函数用来实现对于链表的判空
int  if_empty(PNODE pHead) {
	if (pHead->pNext == NULL)
		return 1;//说明就是为空,返回1
	else
		return 0;
}

//创建一个函数实现求链表的长度
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



//创建一个函数实现对于链表的插入
//在链表的第pos个节点的前面插入一个人新的结点,该节点的值为val,并且pos的值从1开始
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
		printf("动态内存分配失败\n");
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




//创建一个函数实现删除元素
int delete_list(PNODE pHead, int pos,int* val) {//第三个参数就是将删除的参数给了输出
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
	//删除p节点后面的节点
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return 1;
}

//创建一个函数实现对于链表的排序
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
