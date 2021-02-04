#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
//介绍递归
//一个函数直接或者间接调用自己,递归是用栈实现,后调用先返回,所以用栈
//也就是:当有多个函数相互调用时,按照"后调用先返回"的原则,上述函数之间的信息传递和控制转移必须借助"栈"来实现
//即整个系统将整个程序运行时所需的数据空间安排在一个栈中,每当调用一个函数时,就在栈顶分配一个存储区,
//进行压栈操作,每当一个函数退出时,就释放他的存储区,进行出栈操作,当前运行函数永远都在栈顶位置

//一个函数为神魔自己可以调用自己
//一个函数的运行期间调用另一个函数时,在运行被调用函数之前,系统需要完成的三件事情:
//1.将所有的实际参数,返回地址等信息传递给被调用函数保存
//2.为被调用函数的局部变量(包括形参)分配存储空间
//3.将控制转移到被调用函数的入口

//被调用函数返回主调函数之前完成的三件事情:
//1.保存被调函数的返回结果
//2.释放被调函数所占的存储空间
//3.依照被调函数保存的返回地址将控制转移到调用函数

int g(int m);
//举例子展示调用栈
int f(int n) {
	n = g(n);
	return n;
}
int g(int m) {
	m = m * 2;
	return m;
}

//定义三个函数
//void f();
//void g();
//void k();
//void f() {
//	printf("FFFFF\n");
//	g();
//	printf("11111\n");
//	printf("f()执行完毕\n");
//}
//void g() {
//	printf("GGGGG\n");
//	k();
//	printf("22222\n");
//	printf("k()执行完毕\n");
//}
//void k() {
//	printf("KKKKK\n");
//	printf("k()执行完毕\n");
//}


//自己调用自己,必须知道什么时候不再调用自己,也就是要有递归输出条件
//void f(int n) {
//	if(n == 1)
//	printf("哈哈\n");
//	else {
//		printf("%d\n", n);
//		f(n - 1);
//	}
//}

//程序展示间接调用自己
//void f(int n){
//	g(n);
//
//}
//void g(int m) {
//	f(m);
//}



//递归例子:
//1.求阶乘n! = n * n - 1* n - 2 *.......1!
//循环写:
int fun1(int  n) {
	int result = 1;
	for (int i = n; i >= 1; --i) {
		result *= i;
	}
	return result;
}
//递归写
long fun2(long  n) {
	//先写递归条件
	if (n == 1)
		return 1;
	else {
		printf("%d\n", n);
		return n * fun2(n - 1);
	}
}

//2.循环写1+......n的和
int sum1(int n) {
	int sum = 0;
	for (int i = n; i >= 1; --i) {
		sum += i;
	}
	return sum;
}
//递归写求和
int  sum2(int n) {
	if (n == 1)
		return 1;
	else {
		return n + sum2(n - 1);//直接调用自己
	}
}

//3.汉诺塔,递归实现

int main() {
	//printf("请输入您想要求得数:");
	//int n = 0;
	//scanf("%d", &n);
	///*printf("您输入数的阶乘为:%ld\n", fun2(n));*/
	//printf("您想要求得和为:%d\n", sum2(n));
	printf("%d\n", f(5));
	return 0;
}
