#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

//�ݹ��������������:
//1.�ݹ������һ����ȷ����ֹ����
//2.�ú�������������ݹ�ģ�����ڵݼ�
//3.���ת�������ǿɽ��(ʲôʱ���õݹ�)

//ѭ���͵ݹ�Ĺ�ϵ
//ת������:.......
//��ȱ��
//��ŵ������

//�ݹ��Ӧ��:��,ɭ��,����ͼ�Ĵ�����㷨��������ǵݹ�ʵ��,�ܶ���ѧ��ʽҲ��
void hannuota(int n, char a, char b, char c) {//n�����Ӵ�a����b�Ƶ�c
	//�����һ������,ֱ�ӽ�һ�����Ӵ�a�ƶ���c��
	//����,�Ƚ�a�����ϵ�n-1�����ӽ���c�ƶ���b,ֱ�ӽ�a�ϵ����Ӵ�a�Ƶ�c��,���b�ϵ�n-1�����ӽ���a�Ƶ�c��
	if (n == 1)
		printf("�����Ϊ%d������ֱ�Ӵ�%c�����ƶ���%c����\n", n, a, c);
	else {
		hannuota(n - 1, a, c, b);
		printf("�����Ϊ%d������ֱ�Ӵ�%c�����ƶ���%c����\n", n, a, c);
		hannuota(n - 1, b, a, c);
	}
}


int main() {
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	printf("���������ӵĸ���:");
	int n = 0;
	scanf("%d", &n);
	hannuota(n, 'A', 'B', 'C');//n�����Ӵ�A����B�Ƶ�C
	return 0;

}