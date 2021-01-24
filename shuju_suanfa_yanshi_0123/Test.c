#include<stdio.h>
#include<stdlib.h>//包含了exit函数
#include<string.h>
#include<malloc.h>
//定义了一个数据类型,该数据类型的名字叫作struct Arr,三个成员
struct Arr {
	int* pBase;//存储数组的第一个元素的地址
	int  len;  //表示数组所能容纳的最大元素的个数
	int cen;//当前数组有效元素的个数
	//int increment;//自动增长因子.这里暂且不要是因为想要将长度固定
};

//方法一:追加:append
//方法二:插入:insert
//方法三:删除:delete
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
//bool这里只是想要表现的类型为boolean,但是没有boolean,只有int所以理解最重要


//定义一个函数用来实现初始化
void init_arr(struct Arr* array, int length) {
	/*array->len = 99;
	(*array).len = 100;*/
	array->pBase = (int*)malloc(sizeof(int) * length);
	if (array->pBase == NULL)//意思就是分配失败的情况下
		{
		printf("动态内存分配使失败");
	exit(-1);
	}
	else
	{
		array->len = length;
		array->cen = 0;
	}
	return;
}

//定义一个函数来判断数组是否为空
int is_empty(struct Arr* array) {
	if (array->cen == 0)//有限元素合个数为0个的时候为空
		return 1;
	else
		return 0;
}
//定义一个函数用来实现判断函数是否为满
int is_full(struct Arr* array) {
	if (array->cen == array->len)
		return 1;
	else
		return 0;
}

//定义一个函数用来实现输出
void show_arr(struct Arr* array) {
	/*if (array->len == 0) {//这样写可以,但是不如写一个函数来判断是否为空更方便
		printf("该数组为空");
	}*/
	if (is_empty(array))
	{
		printf("数组为空\n");
	}
	else {//输出该数组的元素
		for (int i = 0; i < array->cen; ++i)
			printf("%d     ",array->pBase[i]);
		printf("\n");
	}
}
//定义一个函数用来实现数组的追加
int append_arr(struct Arr* array,int val) {
	if (is_full(array)) {
		printf("函数已经满了,不可以添加\n");
		return 0;
	}
	else {
		array->pBase[array->cen] = val;
		(array->cen)++;
		return 1;//添加元素成功
	}
}
//定义一个函数用来实现对于函数的插入元素
int insert_arr(struct Arr* array,int pos,int val) {//第二个参数就是插入的位置(从1开始,也就是说想要在3插入,
	                                               //实际插入的位置为2)
	                                             //第三个位置就是插入的数字
	if (is_full(array)) {
		printf("数组已经满了,不能再插入\n");
		return 0;
	}
	else {
		if (pos < 1 || pos > (array->cen + 1 )) {
			printf("位置不合法\n");
			return 0;
		}
		else {
			int i;
			for (i = array->cen - 1; i >= pos - 1; --i) {
				array->pBase[i + 1] = array->pBase[i];
			}
			array->pBase[pos - 1] = val;
			array->cen++;
			printf("插入成功\n");
			return 1;
		}
	}
}
//定义一个函数,实现对于数组的元素的删除
int delete_arr(struct Arr* array,int pos) {//删除元素的位置
	if (is_empty(array)) {
		printf("数组为空不可以进行删除元素操作\n");
		return 0;
	}
	else if (pos < 1 || pos > array->cen) {
		printf("位置不合法,请重新进行删除操作\n");
		return 0;
	}
	else {
		int temp = array->pBase[pos - 1];
		for (int i = pos - 1; i <= array->cen - 1; ++i) {
			array->pBase[i] = array->pBase[i + 1];
		}
		array->cen--;
		printf("删除成功,删除的值为:%d\n",temp);
		return 1;
	}
}
//定义一个函数,用来实现对于元素的删除
int  delete_arr2(struct Arr* array, int pos, int* pVal) {//第三个参数就是想通过指针修改该值
	if (is_empty(array)) {
		printf("数组为空不可以进行删除元素操作,");
		return 0;
	}
	else if (pos < 1 || pos > array->cen) {
		printf("位置不合法,");
		return 0;
	}
	else {
		*pVal = array->pBase[pos - 1];
		for (int i = pos; i < array->cen; ++i) {
			array->pBase[i - 1] = array->pBase[i];
		}
		printf("删除成功,");
		array->cen--;
		return 1;
	}
}
//定义一个函数实现对于元素的查询
int get_arr(struct Arr* array,int pos) {//给出位置来给出元素的内容
	if (is_empty(array)) {
		printf("数组中元素为空,查询失败\n");
		return -1;
	}
	if (pos < 1 || pos > array->cen) {
		printf("查询的位置不合法,查询失败\n");
		return -1;
	}
	return  array->pBase[pos - 1];
}



//定义一个函数用来实现对于数组元素的倒置
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
//定义一个函数,用来实现对于数组的排序
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
	printf("排序完毕!\n");
}


int main() {
	struct Arr arr ;
	int val;//这个就是下面用来实现调用函数的时候进行的参数传值
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
		printf("删除的元素是:%d\n", val);
	}
	else {
		printf("删除失败\n");
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
		printf("删除的元素是:%d\n", val);
	}
	else {
		printf("删除失败\n");
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
	printf("查询的元素为:%d\n", get_arr(&arr, 5));
	show_arr(&arr);
	if (get_arr(&arr, 10) != -1)
	printf("查询的元素为:%d\n", get_arr(&arr, 10));
	show_arr(&arr);
	delete_arr(&arr, 1);
	show_arr(&arr);
	if (get_arr(&arr, 6) != -1)
	printf("查询的元素为:%d\n", get_arr(&arr, 6));
	show_arr(&arr);
	return 0;
}