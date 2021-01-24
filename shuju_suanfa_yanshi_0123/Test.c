#include<stdio.h>
#include<stdlib.h>//������exit����
#include<string.h>
#include<malloc.h>
//������һ����������,���������͵����ֽ���struct Arr,������Ա
struct Arr {
	int* pBase;//�洢����ĵ�һ��Ԫ�صĵ�ַ
	int  len;  //��ʾ�����������ɵ����Ԫ�صĸ���
	int cen;//��ǰ������ЧԪ�صĸ���
	//int increment;//�Զ���������.�������Ҳ�Ҫ����Ϊ��Ҫ�����ȹ̶�
};

//����һ:׷��:append
//������:����:insert
//������:ɾ��:delete
//void init_arr();
//bool append_arr();
//bool insert_arr();
//bool delete_arr();
//bool get();
//bool is_empty();
//bool is_full();
//void sort_arr();
//void show_arr();
//void inverson_arr();
//bool����ֻ����Ҫ���ֵ�����Ϊboolean,����û��boolean,ֻ��int�����������Ҫ


//����һ����������ʵ�ֳ�ʼ��
void init_arr(struct Arr* array, int length) {
	/*array->len = 99;
	(*array).len = 100;*/
	array->pBase = (int*)malloc(sizeof(int) * length);
	if (array->pBase == NULL)//��˼���Ƿ���ʧ�ܵ������
		{
		printf("��̬�ڴ����ʹʧ��");
	exit(-1);
	}
	else
	{
		array->len = length;
		array->cen = 0;
	}
	return;
}

//����һ���������ж������Ƿ�Ϊ��
int is_empty(struct Arr* array) {
	if (array->cen == 0)//����Ԫ�غϸ���Ϊ0����ʱ��Ϊ��
		return 1;
	else
		return 0;
}
//����һ����������ʵ���жϺ����Ƿ�Ϊ��
int is_full(struct Arr* array) {
	if (array->cen == array->len)
		return 1;
	else
		return 0;
}

//����һ����������ʵ�����
void show_arr(struct Arr* array) {
	/*if (array->len == 0) {//����д����,���ǲ���дһ���������ж��Ƿ�Ϊ�ո�����
		printf("������Ϊ��");
	}*/
	if (is_empty(array))
	{
		printf("����Ϊ��\n");
	}
	else {//����������Ԫ��
		for (int i = 0; i < array->cen; ++i)
			printf("%d     ",array->pBase[i]);
		printf("\n");
	}
}
//����һ����������ʵ�������׷��
int append_arr(struct Arr* array,int val) {
	if (is_full(array)) {
		printf("�����Ѿ�����,���������\n");
		return 0;
	}
	else {
		array->pBase[array->cen] = val;
		(array->cen)++;
		return 1;//���Ԫ�سɹ�
	}
}
//����һ����������ʵ�ֶ��ں����Ĳ���Ԫ��
int insert_arr(struct Arr* array,int pos,int val) {//�ڶ����������ǲ����λ��(��1��ʼ,Ҳ����˵��Ҫ��3����,
	                                               //ʵ�ʲ����λ��Ϊ2)
	                                             //������λ�þ��ǲ��������
	if (is_full(array)) {
		printf("�����Ѿ�����,�����ٲ���\n");
		return 0;
	}
	else {
		if (pos < 1 || pos > (array->cen + 1 )) {
			printf("λ�ò��Ϸ�\n");
			return 0;
		}
		else {
			int i;
			for (i = array->cen - 1; i >= pos - 1; --i) {
				array->pBase[i + 1] = array->pBase[i];
			}
			array->pBase[pos - 1] = val;
			array->cen++;
			printf("����ɹ�\n");
			return 1;
		}
	}
}
//����һ������,ʵ�ֶ��������Ԫ�ص�ɾ��
int delete_arr(struct Arr* array,int pos) {//ɾ��Ԫ�ص�λ��
	if (is_empty(array)) {
		printf("����Ϊ�ղ����Խ���ɾ��Ԫ�ز���\n");
		return 0;
	}
	else if (pos < 1 || pos > array->cen) {
		printf("λ�ò��Ϸ�,�����½���ɾ������\n");
		return 0;
	}
	else {
		int temp = array->pBase[pos - 1];
		for (int i = pos - 1; i <= array->cen - 1; ++i) {
			array->pBase[i] = array->pBase[i + 1];
		}
		array->cen--;
		printf("ɾ���ɹ�,ɾ����ֵΪ:%d\n",temp);
		return 1;
	}
}
//����һ������,����ʵ�ֶ���Ԫ�ص�ɾ��
int  delete_arr2(struct Arr* array, int pos, int* pVal) {//����������������ͨ��ָ���޸ĸ�ֵ
	if (is_empty(array)) {
		printf("����Ϊ�ղ����Խ���ɾ��Ԫ�ز���,");
		return 0;
	}
	else if (pos < 1 || pos > array->cen) {
		printf("λ�ò��Ϸ�,");
		return 0;
	}
	else {
		*pVal = array->pBase[pos - 1];
		for (int i = pos; i < array->cen; ++i) {
			array->pBase[i - 1] = array->pBase[i];
		}
		printf("ɾ���ɹ�,");
		array->cen--;
		return 1;
	}
}
//����һ������ʵ�ֶ���Ԫ�صĲ�ѯ
int get_arr(struct Arr* array,int pos) {//����λ��������Ԫ�ص�����
	if (is_empty(array)) {
		printf("������Ԫ��Ϊ��,��ѯʧ��\n");
		return -1;
	}
	if (pos < 1 || pos > array->cen) {
		printf("��ѯ��λ�ò��Ϸ�,��ѯʧ��\n");
		return -1;
	}
	return  array->pBase[pos - 1];
}



//����һ����������ʵ�ֶ�������Ԫ�صĵ���
void inversion_arr(struct Arr* array) {
	int i = 0;
	int j = array->cen - 1;
	int temp = 0;
	while (i < j) {
		temp = array->pBase[i];
		array->pBase[i] = array->pBase[j];
		array->pBase[j] = temp;
		++i;
		--j;
	}
	return;
}
//����һ������,����ʵ�ֶ������������
void sort_arr(struct Arr* array) {
	for (int i = 0; i < array->cen; i++) {
		for (int j = 0; j < array->cen - i - 1; j++) {
			if (array->pBase[j] > array->pBase[j + 1]) {
				int tmp = array->pBase[j];
				array->pBase[j] = array->pBase[j + 1];
				array->pBase[j + 1] = tmp;
			}
		}
	}
	printf("�������!\n");
}


int main() {
	struct Arr arr ;
	int val;//���������������ʵ�ֵ��ú�����ʱ����еĲ�����ֵ
	init_arr(&arr,6);
	//printf("%d", arr.len);
	show_arr(&arr);
	append_arr(&arr, 1);
	show_arr(&arr);
	append_arr(&arr, 2);
	show_arr(&arr); 
	append_arr(&arr, 3);
	show_arr(&arr);  
	append_arr(&arr, 5);
	show_arr(&arr); 
	insert_arr(&arr, 3, 9);
	show_arr(&arr);
	insert_arr(&arr, 6, 10);
	show_arr(&arr);
	delete_arr(&arr, 0);
	show_arr(&arr);
	delete_arr(&arr, 7);
	show_arr(&arr);
	delete_arr(&arr, 6);
	show_arr(&arr);
	delete_arr(&arr, 2);
	show_arr(&arr);
	delete_arr(&arr, 5);
	show_arr(&arr);
	delete_arr(&arr, 4);
	show_arr(&arr);
	if (delete_arr2(&arr, 0, &val))
	{
		printf("ɾ����Ԫ����:%d\n", val);
	}
	else {
		printf("ɾ��ʧ��\n");
	}
	show_arr(&arr);
	delete_arr(&arr, 2);
	show_arr(&arr);
	delete_arr(&arr, 1);
	show_arr(&arr);
	delete_arr(&arr, 1);
	show_arr(&arr);
	if (delete_arr2(&arr , 1, &val))
	{
		printf("ɾ����Ԫ����:%d\n", val);
	}
	else {
		printf("ɾ��ʧ��\n");
	}
	show_arr(&arr);
	printf("\n\n");
	append_arr(&arr, 5);
	append_arr(&arr, 1);
	append_arr(&arr, 2);
	append_arr(&arr, 1);
	append_arr(&arr, 7);
	append_arr(&arr, 10);
	sort_arr(&arr);
	show_arr(&arr);
	if(get_arr(&arr, 5) != -1)
	printf("��ѯ��Ԫ��Ϊ:%d\n", get_arr(&arr, 5));
	show_arr(&arr);
	if (get_arr(&arr, 10) != -1)
	printf("��ѯ��Ԫ��Ϊ:%d\n", get_arr(&arr, 10));
	show_arr(&arr);
	delete_arr(&arr, 1);
	show_arr(&arr);
	if (get_arr(&arr, 6) != -1)
	printf("��ѯ��Ԫ��Ϊ:%d\n", get_arr(&arr, 6));
	show_arr(&arr);
	return 0;
}