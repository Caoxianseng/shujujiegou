#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
int main() {
	int a[10] = { 4, 10, 2, 8, 6 };//静态分配
	int len;
	printf("请输入您想要分配的长度:len = ");
	scanf("%d", &len);
	int* pArr = (int*)malloc(sizeof(int) * len);//动态分配
	for (int i = 0; i < len; i++) {
		scanf("%d", pArr+i);
	}
	for (int i = 0; i < len; i++) {
		printf("%d\n", *(pArr + i));
	}
	free(pArr);//释放20个字节

	return 0;
}