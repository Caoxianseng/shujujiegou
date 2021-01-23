#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Student {
	int sid;
	char name[200];
	int age;
};
void fun(struct Student* str) {//用来实现对于结构体的赋值
	/*printf("请为编号赋值:\n");
	scanf("%d", str->sid);
	printf("请为年龄赋值:\n");
	scanf("%d", str->age);
	printf("请为名字赋值:");
	for (int i = 0; i < 5; i++) {
		scanf("%c", (str->name)[i]);
	}*/
	(*str).sid = 99;
	(*str).age = 22;
	strcpy(str->name, "caowen");
	str->age = 23;
}
void g(struct Student str) {//这种就是耗内存
	printf("%d   %s %d\n", str.age, str.name, str.sid);
}
void g2(struct Student* str1) {
	printf("%d %s %d\n", str1->age, str1->name, str1->sid);
}
int main() {
	/*struct Student st = { 1000,"zhangsan",20 };//这就是一个变量
	printf("%d   %s %d\n", st.age, st.name, st.sid);
	struct Student* pst = NULL;
	pst = &st;
	pst->age = 21;
	printf("%d   %s %d",pst->age, (*pst).name, st.sid);
	return 0;

	int i;//这里就是垃圾值*/

	struct Student st2;
	fun(&st2);
	g2(&st2);

}