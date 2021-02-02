#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#define LENGTH 6

//静态队列通常都必须是循环队列
//循环队列:
//1.为什么是循环队列:
//答案:为了防止浪费,也就是将r与f指针移动到最后又返回到数组开始实现了循环利用

//2.至少需要几个参数
//答案:front 和 rear

//3.各个参数的意义
//front:指向第一个元素,rear指向队尾下一个元素,但是rear这样说是不对的,准确的说就是:
//三种场合下两个参数的作用不一样
//1.队列初始化
//front和rear的值都是0
//2.队列非空
//front代表的是队列的第一个元素,rear代表的是最后一个有效元素的下一个元素
//3.队列为空
//front和rear指向的是相等,但是不一定非得是0(这一点很重要,是因为与上面的相照应,为什么用循环队列的原因)


//4.循环队列的入队伪算法
//入队第一步:先将元素放到对应的位置,也就是rear指向的位置,然后将rear移动,不能简单的进行加一,要写成:
//rear = (rear + 1)%(数组的长度)

//5.出队伪算法
//出队是从front出,也就是front移动,就要++,rear在哪个位置都可以,但是也面临溢出的问题
//于是fornt = (fornt + 1) % 数组长度

//6.如何判断是否为空/满
//判断是否为空:如果front的值与rear的值相等,该队列一定为空
//if(rear == front)就是为空
//front和rear的大小是没有任何规律的

//判断是否为满:当rear加一或者取余之后等于了front就是为满
//一般是加一个数量的判断变量就可以,但是一般最正常的做法是只用其中数组减一个元素
//也就是说,rear和front紧挨着,就是满了,n个元素,放了n-1个元素就算是满了
//两种方式:1.多增加一个参数,标识参数
//2.少用一个元素,紧挨着就是队列满了,而且是rear比front小,这个小的意思就是说rear追上front,也就是下面:
//if( (rear + 1 ) % 数组长度 == f)就是满了

typedef struct Queue {
	int* pBase;
	int front;
	int rear;
}QUEUE;

//定义一个函数用来实现初始化
void init(QUEUE *);
//判断队列是否为满
int full_queue(QUEUE*);
//定义一个函数实现队列的入队
int en_queue(QUEUE*, int);
//实现一个函数用来进行是否为空的判断
int empty_queue(QUEUE*);
//定义一个函数实现队列的输出
void traverse_queue(QUEUE*);
//定义一个函数实现出队
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

void init(QUEUE* Queue) {//具体实现队列的初始化函数
	Queue->pBase = (int*)malloc(sizeof(int) * LENGTH);
	Queue->front = 0;
	Queue->rear = 0;
}

int full_queue(QUEUE * queue) {
	if ((queue->rear + 1) % LENGTH == queue->front) {
		return 1;//也就是满了
	}
	else {
		return 0;//也就是不为满
	}
}

int en_queue(QUEUE* queue, int val) {//具体实现入队函数
	//先判断队列是否为满
	if (full_queue(queue)){
		return 0;//说明队列满了,入队失败
	}
	else {//如果不满.数就安放在队尾也就是rear指向的位置
		queue->pBase[queue->rear] = val;
		queue->rear = (queue->rear + 1) % LENGTH;//也就是更新rear的值
		return 1;//入队成功
	}
}

int empty_queue(QUEUE* queue) {
	if (queue->front == queue->rear) {
		return 1;//也就是为空
	}
	else {
		return 0;
	}
}

void traverse_queue(QUEUE* queue) {//具体实现遍历队列
	//先判断是否为空
	if (empty_queue(queue)) {
		printf("队列为空,无法遍历\n");
	}
	else {
	int i = queue->front;
	while (i != queue->rear) {
		printf("%d\t", queue->pBase[i]);
		i = (i + 1) % LENGTH;
	}
	printf("\n");
	}
	//先把i指向front,只要i不是rear,就输出,一旦就是rear时,那个位置无效
}

int out_queue(QUEUE* queue){//第二个参数用来实现保存输出该值
	if (empty_queue(queue)) {
		printf("队列为空,出队失败\n");
		return 0;//出队失败
	}
	else {
		printf("删除的值:%d\n", queue->pBase[queue->front]);
		queue->front = (queue->front + 1) % LENGTH;
		return 1;
	}
}