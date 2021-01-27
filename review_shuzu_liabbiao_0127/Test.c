#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
//���ȴ���һ���ṹ��,����ʵ�ֶ���������÷�
typedef struct Arr{
  int* pBase;//����������׵�ַ
  int len;//����������ĳ���
  int cen;//Ŀǰ��������Ч����
}Arr;

void init_shuzu(Arr* array,int length);
void append_arr(Arr* array,int val);
void insert_arr(Arr* array,int pos,int val);
void delete_arr(Arr* array,int pos);
void get_arr(Arr* array,int pos);
int is_empty(Arr* array);
int is_full(Arr* array);
void sort_arr(Arr* array);
void show_arr(Arr* array);
void inverson_arr(Arr* array);

int main(){
  Arr arr ;
  init_shuzu(&arr,10);

  append_arr(&arr,5);
  append_arr(&arr,1);
  append_arr(&arr,9);
  append_arr(&arr,3);
  append_arr(&arr,2);
  show_arr(&arr);

  insert_arr(&arr,0,10);
  insert_arr(&arr,5,10);
  insert_arr(&arr,6,10);
  insert_arr(&arr,9,10);
  show_arr(&arr);

  delete_arr(&arr,8);
  delete_arr(&arr,7);
  delete_arr(&arr,5);
  show_arr(&arr);

  get_arr(&arr,0);
  get_arr(&arr,6);
  get_arr(&arr,5);

  sort_arr(&arr);
  show_arr(&arr);

  inverson_arr(&arr);
  show_arr(&arr);

  return 0;
}



void init_shuzu(Arr* array,int length){//����һ������ֻ��Ҫ�������������������Ѵ����õ�����ʹ�������ĳ���
  array->pBase = (int*)malloc(sizeof(int)*length);//���ṹ���еĻ���ַ��̬�����ڴ�ռ�
  if(array->pBase == NULL){//���Ƿ���ʧ�ܵ����
    printf("�ڴ����ʧ��\n");
    exit(-1);
  }
  else{//���ٳɹ��Ժ�ͽ����˳�ʼ��,Ҳ����һ��ʼ����Ч����Ϊ0,���ǳ���ȴ�Ѿ�ȷ��
    array->len = length;
    array->cen = 0;
  }
  return;
}



int is_empty(Arr* array){//����һ����������ʵ�ֶ���������п�
  if(array->cen == 0)
  return 1;//˵���������Ϊ��
  else
  return 0;//˵�����鲻�ǿ�,˵���������Ч����Ϊ��Ϊ0
}



int is_full(Arr* array){//����һ����������ʵ�ֶ��������Ƿ�Ϊ��
  if(array->cen == array->len)
  return 1;//˵�������Ѿ�����
  else
  return 0;//˵�����黹û����
}



void get_arr(Arr* array,int pos){//�ڶ�����������ʵ�ֶ��ڲ�ѯԪ�ص�λ������
  if(is_empty(array)){
    printf("����Ϊ��,��ѯʧ��\n");
    return ;//�������Ϊ�վͲ����Բ�ѯ
  }

  if(pos < 1 || pos > array->cen){
    printf("�����λ�ò��������,�����µ��ú���\n");
  return ;//���λ�ò��Ծͻ᷵��
}
  printf("������ѯ�ĵ�%d��Ԫ��Ϊ:%d\n",pos,array->pBase[pos-1]);
}



void delete_arr(Arr* array,int pos){//����һ������ʵ��Ԫ�ص�ɾ��
  int* val;
  if(is_empty(array)){
    printf("������Ϊ��,�޷�����ɾ��\n");
    return;
  }
  if(pos < 1 || pos > array->cen){
    printf("ɾ����Ԫ��λ��������,ɾ��ʧ��\n");
    return;
  }
  *val = array->pBase[pos - 1];
  for(int i = pos; i < array->cen; ++i){//ѭ���ĳ�ֵΪ��һ��Ҫɾ����Ԫ��Ҳ����pos = i,��Ϊ
    //pBase[i]=pBase+i,��4Ϊ����ɾ�����ĸ�ʱ,��ʱ��iΪ4ʱ����ָ����ǵ����Ԫ��
    //�������Ԫ�ظ��˵��ĸ�,Ҳ���ǽ�i����i-1,Ҳ����������һ��,���������������һ��Ԫ�شﲻ��,
    //Ҳ����cen���������,�����Ϊcen
    array->pBase[i - 1] = array->pBase[i];
  }
  array->cen--;//��ɾ���Ժ�Ҫ������Ч�����ļ�1
  printf("ɾ���ɹ�,ɾ����Ԫ��Ϊ:%d\n",*val);
  return;
}



void show_arr(Arr* array){
  if(is_empty(array)){
    printf("������Ϊ��,�޷��������\n");
    return;
  }
  for(int i = 0; i < array->cen; i++){//���Ǽ򵥵ı������
    printf("%d\t",array->pBase[i]);
  }
  printf("\n");
  return;
}




void append_arr(Arr* array,int val){
  //��Ҫ�ж��Ƿ�Ϊ��,��������Ͳ��ܽ���׷��
  if(is_full(array)){
    printf("��������,�����Ի�����׷��\n");
    return;
  }
  array->pBase[array->cen] = val;
  array->cen++;
  return;
}




void insert_arr(Arr* array,int pos,int val){//�ڶ�����������λ��,����������������Ҫ����Ԫ�ص�����
  if(is_full(array)){
    printf("��������,�����Ի����в������\n");
    return;
  }
  if(pos < 1 || pos > array->cen + 1){
    printf("�����Ԫ��λ��������,����ʧ��\n");
    return;
  }
  for(int i = array->cen - 1; i >= pos - 1; --i){
    array->pBase[i+1] = array->pBase[i];
  }
  array->pBase[pos-1] = val;
  array->cen++;
  printf("����ɹ�\n");
  return;
}



void sort_arr(Arr* array){
  if(is_empty(array)){
    printf("������Ϊ��,�޷���������\n");
    return;
  }
  for(int i = 0; i < array->cen; i++){
    for(int j = i; j < array->cen - i - 1; j++){
      if(array->pBase[j] > array->pBase[j+1]){
        int temp = array->pBase[j];
        array->pBase[j] = array->pBase[j+1];
        array->pBase[j+1] = temp;
      }
    }
  }
}


void inverson_arr(Arr* array){
  if(is_empty(array)){
    printf("������Ϊ��,�޷����е���\n");
    return;
  }
  int i = 0;
  int j = array->cen - 1;
  while(i < j){
    int temp = array->pBase[i];
    array->pBase[i] = array->pBase[j];
    array->pBase[j] = temp;
    i++;
    j--;
  }
  return;
}
