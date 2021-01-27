#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
//首先创建一个结构体,用来实现对于数组的用法
typedef struct Arr{
  int* pBase;//整个数组的首地址
  int len;//所创建数组的长度
  int cen;//目前数组中有效个数
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



void init_shuzu(Arr* array,int length){//创建一个数组只需要两个参数就是主函数已创建好的数组和创建数组的长度
  array->pBase = (int*)malloc(sizeof(int)*length);//给结构体中的基地址动态开辟内存空间
  if(array->pBase == NULL){//这是分配失败的情况
    printf("内存分配失败\n");
    exit(-1);
  }
  else{//开辟成功以后就进行了初始化,也就是一开始的有效个数为0,但是长度却已经确定
    array->len = length;
    array->cen = 0;
  }
  return;
}



int is_empty(Arr* array){//创建一个函数用来实现对于数组的判空
  if(array->cen == 0)
  return 1;//说明数组就是为空
  else
  return 0;//说明数组不是空,说明数组的有效个数为不为0
}



int is_full(Arr* array){//创建一个函数用来实现对于数组是否为满
  if(array->cen == array->len)
  return 1;//说明数组已经满了
  else
  return 0;//说明数组还没有满
}



void get_arr(Arr* array,int pos){//第二个参数就是实现对于查询元素的位置条件
  if(is_empty(array)){
    printf("数组为空,查询失败\n");
    return ;//如果数组为空就不可以查询
  }

  if(pos < 1 || pos > array->cen){
    printf("输入的位置不满足情况,请重新调用函数\n");
  return ;//如果位置不对就会返回
}
  printf("你所查询的第%d个元素为:%d\n",pos,array->pBase[pos-1]);
}



void delete_arr(Arr* array,int pos){//创建一个函数实现元素的删除
  int* val;
  if(is_empty(array)){
    printf("该数组为空,无法进行删除\n");
    return;
  }
  if(pos < 1 || pos > array->cen){
    printf("删除的元素位置有问题,删除失败\n");
    return;
  }
  *val = array->pBase[pos - 1];
  for(int i = pos; i < array->cen; ++i){//循环的初值为第一个要删除的元素也就是pos = i,因为
    //pBase[i]=pBase+i,以4为例子删除第四个时,这时的i为4时就是指向的是第五个元素
    //将第五个元素给了第四个,也就是将i给了i-1,也就是下面这一句,结束条件就是最后一个元素达不到,
    //也就是cen这个不满足,即最后为cen
    array->pBase[i - 1] = array->pBase[i];
  }
  array->cen--;//在删除以后还要进行有效个数的减1
  printf("删除成功,删除的元素为:%d\n",*val);
  return;
}



void show_arr(Arr* array){
  if(is_empty(array)){
    printf("该数组为空,无法进行输出\n");
    return;
  }
  for(int i = 0; i < array->cen; i++){//就是简单的遍历输出
    printf("%d\t",array->pBase[i]);
  }
  printf("\n");
  return;
}




void append_arr(Arr* array,int val){
  //先要判断是否为满,如果是满就不能进行追加
  if(is_full(array)){
    printf("数组满了,不可以换进行追加\n");
    return;
  }
  array->pBase[array->cen] = val;
  array->cen++;
  return;
}




void insert_arr(Arr* array,int pos,int val){//第二个参数就是位置,第三个参数就是想要插入元素的内容
  if(is_full(array)){
    printf("数组满了,不可以换进行插入操作\n");
    return;
  }
  if(pos < 1 || pos > array->cen + 1){
    printf("插入的元素位置有问题,插入失败\n");
    return;
  }
  for(int i = array->cen - 1; i >= pos - 1; --i){
    array->pBase[i+1] = array->pBase[i];
  }
  array->pBase[pos-1] = val;
  array->cen++;
  printf("插入成功\n");
  return;
}



void sort_arr(Arr* array){
  if(is_empty(array)){
    printf("该数组为空,无法进行排序\n");
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
    printf("该数组为空,无法进行倒置\n");
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
