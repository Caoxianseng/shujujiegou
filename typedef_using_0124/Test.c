#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
typedef struct Student {
	int sid;
	char bame[20];
	char sex;
}ST;
typedef struct Student2 {
	int sid;
	int age;
}*PST;//������Ϊ:�ȼ���struct Student * <==> PST

typedef struct Student3 {
	int sid;
}*PST1, ST1;//����������Ϊ:�ȼ���:ST <==> struct Student3, PST1 <==> struct Student3 *

int main() {
	//ST st;//�ȼ���
	//struct Student st2;
	//st.sid = 200;
	//printf("%d\n", st.sid);

	//struct Student2 st3;
	//PST ps = &st3;
	//ps->age = 99;
	//printf("%d", ps->age);

	ST1 st5;
	PST1 ps = &st5;
	ps->sid = 222;
	printf("%d", ps->sid);

	return 0;
}