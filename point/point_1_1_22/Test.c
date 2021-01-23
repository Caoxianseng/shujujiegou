#include<stdio.h>
void f(int* i) {
	*i = 100;
}
//指针与函数,指针与数组
void Show_Array(int* a) {
	for (int i = 0; i < 5; i++) {
		printf("%d     ", *(a + i));
	}
	*a = 2;
}
void Show_array(int a[]) {
	for (int i = 0; i < 5; i++) {
		printf("%d", a[i]);
	}
}
int main() {
	int a[5] = { 1,2,3,4,5 };
	/*printf("%d", a[3]);
	printf("%d", *(a + 3));
	int* p = NULL;
	int* q = NULL;
	int* m = NULL;
	printf("\n");
	printf("%p\n", a + 2);
	printf("%p\n", a + 3);
	printf("%p\n", a + 4);
	//printf("%d\n", a + 3);
	printf("\n");
	p = a + 2;
	m = a + 3;
	q = a + 4;
	printf("%p\n", m - p);
	printf("%p\n", q - m);
	
	if (a[3] == *(a + 3))
		printf("Y");
	else
		printf("N");
	pntf("\n\n");*/
	Show_Array(a);
	printf("\n");
	Show_array(a);
	
	
	
	
	
	
	/*int i = 9;
	f(&i);
	printf("%d", i);*/
	
	
	
	/*int* p = NULL;
	int i = 10;
	p = &i;
	int j;
	j = *p;
	int** q = NULL;
	q = &p;
	printf("%d\n", j);
	**q = 20;
	printf("%d", **q);*/
	//printf("%o", &p);
	return 0;
}