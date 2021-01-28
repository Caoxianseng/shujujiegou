#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
void f(int k) {
	int m = 0;//m实在栈中分配的
	double* q = (double*)malloc(200);//q也是在栈中分配,200也是在堆中分配的
}
   int  main() {
	   int i = 10;//i实在栈中分配的
	   int* p = (int*)malloc(100);//p也是在栈中分配的,这里的100是在堆中分配的
	   return 0;
}