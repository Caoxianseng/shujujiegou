#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

//���ļ�����Ҫ�ĸ���
//1.���:�Ӹ��ڵ㵽��ײ���Ĳ�����Ϊ���
//2.���ڵ��ǵ�һ��
//3.Ҷ�ӽ��:û���ӽڵ�Ľ�����Ҷ�ӽ��
//4.���ն˽ڵ�:ʵ�ʾ��Ƿ�Ҷ�ӽ��,Ҳ�����и����ӵĽ��,���ڵ㿴�����û�к���
//5.��:�ӽڵ�ĸ���

//���ķ���:һ����,������,ɭ��
//�������ķ���:һ�������,��������(ÿһ������������),��ȫ������:���ֻ��ɾ������������ײ����ұߵ��������ɸ����
//�����γɵľͽ�����ȫ������,
//��������������,ɭ�־���N�������ཻ�����ļ���(û��ʲôʵ������)

//���Ĵ洢:һ����������Ҫ�������ռ�Ҳ�����������ʽ�洢�Ļ�,��Ҫ��ת��Ϊ��ȫ������
//���������ʽ�洢����һ���ص���ǿ��Ը��ݽ���Ʋ������ĸ��ڵ���ӽڵ���˭
//�ŵ�:����������һ��,�����ӽڵ�͸��ڵ�,�����ж���û�����Ǻܿ�,����ȱ��:�����ڴ�ռ�̫��

//��ʽ�洢:
//ÿ���ڵ����:������:���һ���������ӵĵ�ַ,����һ���ŵ������Һ��ӵĵ�ַ,�м�һ���ŵ�������

//�������Ĵ洢:����:1.�����Ĵ洢:��ȫ������
//                  2.��ʽ�洢

//һ�����Ĵ洢:��ת��Ϊ��ȫ������
//���ֱ�ʾ����
//1.˫�ױ�ʾ��:��Ϊһ�������������,���������ŵ��Ǹ��׵��±�Ϳ���,�󸸽ڵ�ܷ���
//2.���ӱ�ʾ��:���Ӻܷ���
//3.˫�׺��ӱ�ʾ��:�ۺϾ���˫�ױ�ʾ��,���ܷ���
//4.��������ʾ��,һ����ת��Ϊ�������ķ���:�跨��֤����һ�����ָ����ָ���һ������,��ָ����ָ�������ֵܽ��,
//ֻҪ���������,�Ϳ��Խ�һ����ͨ��ת��Ϊ������,һ�����õ���ת��Ϊ�������϶�û��������,��Ϊ���ڵ�û���ֵ�

//ɭ�ֵĴ洢:
//������һ����ת��Ϊ�������������Ͻ��м�,���������ĸ��ڵ�һ������ֵ�,Ȼ�����ת��,�������һ������û���ֵܵ�

//���ֹ���:����,����,����(������ת��Ϊ���Խṹ)
//�����Ƚ���Ҫ:���ı�������֪���ֱ�����������Ľṹ
//����:
//�������:�ȷ��ʸ��ڵ�,�ٷ���������,������������
//�������:���������������,�ڷ��ʸ��ڵ�,�������ҽڵ�
//�������:�Ⱥ�������������ٺ������������,�ڷ��ʸ��ڵ�
//��֪���ֱ�����ʽ:���б�����һ��������,�Ⱥͺ������һ��
//

//����Ӧ��:
//���ݿ���������֯��һ����Ҫ��ʽ
//����ϵͳ:�Ӹ����̵Ĺ�ϵ�������һ������ϵ
//�����������ļ̳й�ϵ����Ҳ��һ������ϵ
//��������:ÿ��ȡֵ���ʲ�һ��,�������Ϳ���,����һ��֪ʶ

//��ʼ��Ƴ���,��ʽʵ�ֶ������Լ�����
typedef struct BTNode {
	int data;//���ݲ���
	struct BTNode* pLchild;//p��ָ��L������
	struct BTNode* pRchild;//

}BTNODE,* PBTNODE;

PBTNODE CreateBTree();//����һ����������ʵ�ֶ��ڶ������Ĵ���
void PreTraverseBTree(PBTNODE pT);
void InTraverseBTree(PBTNODE pT);
void PostTraverseBTree(PBTNODE pT);

int main() {
	PBTNODE pT = CreateBTree();
	//�������:
	//PreTraverseBTree(pT);
	//InTraverseBTree(pT);
	PostTraverseBTree(pT);
	return 0;
}


//ȷ��һ��������Ҫ�Ĳ���:ֻ��Ҫһ��Ҳ���Ǹ��ڵ�ĵ�ַ�Ϳ���
PBTNODE CreateBTree() {//��̬����
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

//����һ����������ʵ���������
void PreTraverseBTree(PBTNODE pT) {
	if (pT != NULL) {
		printf("%d\n", pT->data);
		//pT->pLchild���Դ�������������
		if (NULL != pT->pLchild) {
			PreTraverseBTree(pT->pLchild);
		}
		if (NULL != pT->pRchild) {
			PreTraverseBTree(pT->pRchild);
		}
	}
}

//����һ����������ʵ���������
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

//����һ����������ʵ�ֺ������
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