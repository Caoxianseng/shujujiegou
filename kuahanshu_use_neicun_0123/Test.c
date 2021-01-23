#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
struct Student {
	int sid;
	int age;
};
struct Student* CreateStudent() {
	struct Student* p = (struct Student*)malloc(sizeof(struct Student));
	p->age = 25;
	p->sid = 1000;
	return p;
}
void ShowStudent(struct Student* pstr) {
	printf("%d %d", pstr->age, pstr->sid);
}
int main() {
	struct Student* ps;
	ps = CreateStudent();
	/*scanf("%d", &(ps->age));
	scanf("%d", &(ps->sid));*/
	ShowStudent(ps);
	return 0;
}