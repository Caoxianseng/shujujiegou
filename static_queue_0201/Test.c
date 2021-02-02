#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#define LENGTH 6

//��̬����ͨ����������ѭ������
//ѭ������:
//1.Ϊʲô��ѭ������:
//��:Ϊ�˷�ֹ�˷�,Ҳ���ǽ�r��fָ���ƶ�������ַ��ص����鿪ʼʵ����ѭ������

//2.������Ҫ��������
//��:front �� rear

//3.��������������
//front:ָ���һ��Ԫ��,rearָ���β��һ��Ԫ��,����rear����˵�ǲ��Ե�,׼ȷ��˵����:
//���ֳ������������������ò�һ��
//1.���г�ʼ��
//front��rear��ֵ����0
//2.���зǿ�
//front������Ƕ��еĵ�һ��Ԫ��,rear����������һ����ЧԪ�ص���һ��Ԫ��
//3.����Ϊ��
//front��rearָ��������,���ǲ�һ���ǵ���0(��һ�����Ҫ,����Ϊ�����������Ӧ,Ϊʲô��ѭ�����е�ԭ��)


//4.ѭ�����е����α�㷨
//��ӵ�һ��:�Ƚ�Ԫ�طŵ���Ӧ��λ��,Ҳ����rearָ���λ��,Ȼ��rear�ƶ�,���ܼ򵥵Ľ��м�һ,Ҫд��:
//rear = (rear + 1)%(����ĳ���)

//5.����α�㷨
//�����Ǵ�front��,Ҳ����front�ƶ�,��Ҫ++,rear���ĸ�λ�ö�����,����Ҳ�������������
//����fornt = (fornt + 1) % ���鳤��

//6.����ж��Ƿ�Ϊ��/��
//�ж��Ƿ�Ϊ��:���front��ֵ��rear��ֵ���,�ö���һ��Ϊ��
//if(rear == front)����Ϊ��
//front��rear�Ĵ�С��û���κι��ɵ�

//�ж��Ƿ�Ϊ��:��rear��һ����ȡ��֮�������front����Ϊ��
//һ���Ǽ�һ���������жϱ����Ϳ���,����һ����������������ֻ�����������һ��Ԫ��
//Ҳ����˵,rear��front������,��������,n��Ԫ��,����n-1��Ԫ�ؾ���������
//���ַ�ʽ:1.������һ������,��ʶ����
//2.����һ��Ԫ��,�����ž��Ƕ�������,������rear��frontС,���С����˼����˵rear׷��front,Ҳ��������:
//if( (rear + 1 ) % ���鳤�� == f)��������

typedef struct Queue {
	int* pBase;
	int front;
	int rear;
}QUEUE;

//����һ����������ʵ�ֳ�ʼ��
void init(QUEUE *);
//�ж϶����Ƿ�Ϊ��
int full_queue(QUEUE*);
//����һ������ʵ�ֶ��е����
int en_queue(QUEUE*, int);
//ʵ��һ���������������Ƿ�Ϊ�յ��ж�
int empty_queue(QUEUE*);
//����һ������ʵ�ֶ��е����
void traverse_queue(QUEUE*);
//����һ������ʵ�ֳ���
int out_queue(QUEUE*);

int main() {
	QUEUE Q;
	int* pval = NULL;

	init(&Q);
	en_queue(&Q, 1);
	en_queue(&Q, 2);
	en_queue(&Q, 3);
	en_queue(&Q, 4);
	en_queue(&Q, 5);
	en_queue(&Q, 6);
	en_queue(&Q, 7);
	en_queue(&Q, 8);
	traverse_queue(&Q);
	out_queue(&Q);
	traverse_queue(&Q);
	out_queue(&Q);
	traverse_queue(&Q);
	out_queue(&Q);
	traverse_queue(&Q);
	out_queue(&Q);
	traverse_queue(&Q);
	out_queue(&Q);
	traverse_queue(&Q);
	out_queue(&Q);
	traverse_queue(&Q);
	return 0;
}

void init(QUEUE* Queue) {//����ʵ�ֶ��еĳ�ʼ������
	Queue->pBase = (int*)malloc(sizeof(int) * LENGTH);
	Queue->front = 0;
	Queue->rear = 0;
}

int full_queue(QUEUE * queue) {
	if ((queue->rear + 1) % LENGTH == queue->front) {
		return 1;//Ҳ��������
	}
	else {
		return 0;//Ҳ���ǲ�Ϊ��
	}
}

int en_queue(QUEUE* queue, int val) {//����ʵ����Ӻ���
	//���ж϶����Ƿ�Ϊ��
	if (full_queue(queue)){
		return 0;//˵����������,���ʧ��
	}
	else {//�������.���Ͱ����ڶ�βҲ����rearָ���λ��
		queue->pBase[queue->rear] = val;
		queue->rear = (queue->rear + 1) % LENGTH;//Ҳ���Ǹ���rear��ֵ
		return 1;//��ӳɹ�
	}
}

int empty_queue(QUEUE* queue) {
	if (queue->front == queue->rear) {
		return 1;//Ҳ����Ϊ��
	}
	else {
		return 0;
	}
}

void traverse_queue(QUEUE* queue) {//����ʵ�ֱ�������
	//���ж��Ƿ�Ϊ��
	if (empty_queue(queue)) {
		printf("����Ϊ��,�޷�����\n");
	}
	else {
	int i = queue->front;
	while (i != queue->rear) {
		printf("%d\t", queue->pBase[i]);
		i = (i + 1) % LENGTH;
	}
	printf("\n");
	}
	//�Ȱ�iָ��front,ֻҪi����rear,�����,һ������rearʱ,�Ǹ�λ����Ч
}

int out_queue(QUEUE* queue){//�ڶ�����������ʵ�ֱ��������ֵ
	if (empty_queue(queue)) {
		printf("����Ϊ��,����ʧ��\n");
		return 0;//����ʧ��
	}
	else {
		printf("ɾ����ֵ:%d\n", queue->pBase[queue->front]);
		queue->front = (queue->front + 1) % LENGTH;
		return 1;
	}
}