#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Student {
	int sid;
	char name[200];
	int age;
};
void fun(struct Student* str) {//����ʵ�ֶ��ڽṹ��ĸ�ֵ
	/*printf("��Ϊ��Ÿ�ֵ:\n");
	scanf("%d", str->sid);
	printf("��Ϊ���丳ֵ:\n");
	scanf("%d", str->age);
	printf("��Ϊ���ָ�ֵ:");
	for (int i = 0; i < 5; i++) {
		scanf("%c", (str->name)[i]);
	}*/
	(*str).sid = 99;
	(*str).age = 22;
	strcpy(str->name, "caowen");
	str->age = 23;
}
void g(struct Student str) {//���־��Ǻ��ڴ�
	printf("%d   %s %d\n", str.age, str.name, str.sid);
}
void g2(struct Student* str1) {
	printf("%d %s %d\n", str1->age, str1->name, str1->sid);
}
int main() {
	/*struct Student st = { 1000,"zhangsan",20 };//�����һ������
	printf("%d   %s %d\n", st.age, st.name, st.sid);
	struct Student* pst = NULL;
	pst = &st;
	pst->age = 21;
	printf("%d   %s %d",pst->age, (*pst).name, st.sid);
	return 0;

	int i;//�����������ֵ*/

	struct Student st2;
	fun(&st2);
	g2(&st2);

}