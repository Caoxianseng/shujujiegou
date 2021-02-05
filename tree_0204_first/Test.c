#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//树的几个重要的概念
//1.深度:从根节点到最底层结点的层数称为深度
//2.根节点是第一层
//3.叶子结点:没有子节点的结点叫做叶子结点
//4.非终端节点:实际就是非叶子结点,也就是有个孩子的结点,根节点看情况有没有孩子
//5.度:子节点的个数

//树的分类:一般树,二叉树,森林
//二叉树的分类:一般二叉树,满二叉树(每一层结点数是满的),完全二叉树:如果只是删除满二叉树最底层最右边的连续若干个结点
//这样形成的就叫做完全二叉树,
//二叉树是有序树,森林就是N个互不相交的树的集合(没有什么实际意义)

//树的存储:一般二叉树如果要以连续空间也就是数组的形式存储的话,就要先转换为完全二叉树
//以数组的形式存储还有一个特点就是可以根据结点推测出其结点的父节点和子节点是谁
//优点:就是上面这一条,查找子节点和父节点,包括判断有没有他们很快,但是缺点:耗用内存空间太大

//链式存储:
//每个节点包括:三部分:左边一块存放其左孩子的地址,右面一块存放的是有右孩子的地址,中间一块存放的是数据

//二叉树的存储:两类:1.连续的存储:完全二叉树
//                  2.链式存储

//一般树的存储:先转换为完全二叉树
//三种表示方法
//1.双亲表示法:因为一般树都是无序的,所以里面存放的是父亲的下标就可以,求父节点很方便
//2.孩子表示法:求孩子很方便
//3.双亲孩子表示法:综合就是双亲表示法,都很方便
//4.二叉树表示法,一般树转换为二叉树的方法:设法保证任意一结点左指针域指向第一个孩子,右指针域指向他的兄弟结点,
//只要满足此条件,就可以将一个普通树转换为二叉树,一个普用的树转换为二叉树肯定没有右子树,因为根节点没有兄弟

//森林的存储:
//就是在一般树转换为二叉树的做法上进行加,将所有树的根节点一起就是兄弟,然后进行转换,但是最后一棵树是没有兄弟的

//三种规则:先序,中序,后序(非线性转换为线性结构)
//两个比较重要:树的遍历和已知两种遍历来求得树的结构
//遍历:
//先序遍历:先访问根节点,再访问左子树,最后访问右子树
//中序遍历:先中序遍历左子树,在访问根节点,最后访问右节点
//后序遍历:先后序遍历左子树再后序遍历右子树,在访问根节点
//已知两种遍历方式:其中必须有一种是中序,先和后就是另一种
//

//树的应用:
//数据库中数据组织的一种重要形式
//操作系统:子父进程的关系本身就是一种树关系
//面向对象中类的继承关系本身也是一种树关系
//哈弗曼树:每种取值概率不一样,编码最快就可以,树的一种知识

//开始设计程序,链式实现二叉树以及遍历
typedef struct BTNode {
	int data;//数据部分
	struct BTNode* pLchild;//p是指针L是左孩子
	struct BTNode* pRchild;//

}BTNODE,* PBTNODE;

PBTNODE CreateBTree();//声明一个函数用来实现对于二叉树的创建
void PreTraverseBTree(PBTNODE pT);
void InTraverseBTree(PBTNODE pT);
void PostTraverseBTree(PBTNODE pT);

int main() {
	PBTNODE pT = CreateBTree();
	//先序输出:
	//PreTraverseBTree(pT);
	//InTraverseBTree(pT);
	PostTraverseBTree(pT);
	return 0;
}


//确定一个链表需要的参数:只需要一个也就是根节点的地址就可以
PBTNODE CreateBTree() {//静态创建
	PBTNODE pA = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pB = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pC = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pD = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pE = (PBTNODE)malloc(sizeof(BTNODE));
	pA->data = 1;
	pB->data = 2;
	pC->data = 3;
	pD->data = 4;
	pE->data = 5;
	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;
	return pA;
}

//创建一个函数用来实现先序输出
void PreTraverseBTree(PBTNODE pT) {
	if (pT != NULL) {
		printf("%d\n", pT->data);
		//pT->pLchild可以代表整个左子树
		if (NULL != pT->pLchild) {
			PreTraverseBTree(pT->pLchild);
		}
		if (NULL != pT->pRchild) {
			PreTraverseBTree(pT->pRchild);
		}
	}
}

//创建一个函数用来实现中序输出
void InTraverseBTree(PBTNODE pT) {
	if (pT != NULL) {
		
		if (NULL != pT->pLchild) {
			InTraverseBTree(pT->pLchild);
		}
		printf("%d\n", pT->data);

		if (NULL != pT->pRchild) {
			InTraverseBTree(pT->pRchild);
		}
	}
}

//创建一个函数用来实现后序输出
void PostTraverseBTree(PBTNODE pT) {
	if (pT != NULL) {

		if (NULL != pT->pLchild) {
			PostTraverseBTree(pT->pLchild);
		}
		if (NULL != pT->pRchild) {
			PostTraverseBTree(pT->pRchild);
		}
		printf("%d\n", pT->data);
	}
}