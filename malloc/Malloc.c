#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
int main() {
	int a[10] = { 4, 10, 2, 8, 6 };//��̬����
	int len;
	printf("����������Ҫ����ĳ���:len = ");
	scanf("%d", &len);
	int* pArr = (int*)malloc(sizeof(int) * len);//��̬����
	for (int i = 0; i < len; i++) {
		scanf("%d", pArr+i);
	}
	for (int i = 0; i < len; i++) {
		printf("%d\n", *(pArr + i));
	}
	free(pArr);//�ͷ�20���ֽ�

	return 0;
}