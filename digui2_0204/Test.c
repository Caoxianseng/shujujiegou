#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

//递归满足的三个条件:
//1.递归必须有一个明确的终止条件
//2.该函数所处理的数据规模必须在递减
//3.这个转换必须是可解的(什么时候用递归)

//循环和递归的关系
//转换方法:.......
//优缺点
//汉诺塔程序

//递归的应用:树,森林,数和图的大多数算法大多数都是递归实现,很多数学方式也是
void hannuota(int n, char a, char b, char c) {//n个盘子从a借助b移到c
	//如果是一个盘子,直接将一个盘子从a移动到c上
	//否则,先将a柱子上的n-1个盘子借助c移动到b,直接将a上的盘子从a移到c上,最后将b上的n-1个盘子借助a移到c上
	if (n == 1)
		printf("将编号为%d的盘子直接从%c柱子移动到%c柱子\n", n, a, c);
	else {
		hannuota(n - 1, a, c, b);
		printf("将编号为%d的盘子直接从%c柱子移动到%c柱子\n", n, a, c);
		hannuota(n - 1, b, a, c);
	}
}


int main() {
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	printf("请输入盘子的个数:");
	int n = 0;
	scanf("%d", &n);
	hannuota(n, 'A', 'B', 'C');//n个盘子从A借助B移到C
	return 0;

}