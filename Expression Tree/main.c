#include <stdio.h>

// Ʈ����� ����ü
typedef struct treeNode {
	int data;
	struct treeNode* left, * right;
}TreeNode;

TreeNode n1 = { 2,NULL,NULL };
TreeNode n2 = { 3,NULL,NULL };
TreeNode n3 = { (int)'+',&n1,&n2 };
TreeNode n4 = { 4,NULL,NULL };
TreeNode n5 = { 5,NULL,NULL };
TreeNode n6 = { (int)'*',&n4,&n5 };
TreeNode n7 = { (int)'+',&n3,&n6 };
TreeNode n8 = { 6,NULL,NULL };
TreeNode n9 = { 7,NULL,NULL };
TreeNode n10 = { (int)'/',&n8,&n9 };
TreeNode n11 = { (int)'-',&n7,&n10 };
TreeNode n12 = { 9,NULL,NULL };
TreeNode n13 = { (int)'+',&n11,&n12 };

TreeNode* root = &n13;

double evaluate(TreeNode* root)
{
	if (root == NULL) return 0; // ������� ��쿡�� ����
	if (root->left == NULL && root->right == NULL) return root->data; // ���� ����� ��쿡�� ������������ data�� �� �ִ� ������ ����

	else {
		double op1 = evaluate(root->left); // ���� �ڽ� = op1
		double op2 = evaluate(root->right); // ������ �ڽ� = op2

		printf("%f %c %f = ", op1, (char)root->data, op2); // ��� �� ���

		switch ((char)root->data) // ��Ģ���� ��� �� ����
		{
		case '+': printf("%f\n", op1 + op2); return op1 + op2;
		case '-': printf("%f\n", op1 - op2);  return op1 - op2;
		case '*': printf("%f\n", op1 * op2); return op1 * op2;
		case '/': printf("%f\n", op1 / op2); return op1 / op2;
		}
	}
}

// �ݺ��� ������� �� ����� ���� ����

// // ���� ����
#define SIZE 100
int top = -1;
TreeNode* stack[SIZE];

// ���� �Լ�
void push(TreeNode* p)
{
	if (top < SIZE - 1) {
		stack[++top] = p;
	}
}

// ���� �Լ�
TreeNode* pop()
{
	TreeNode* p = NULL;
	if (top >= 0) {
		p = stack[top--];
	}
	return p;
}

// ��� ī���� �Լ�
void node_counter(TreeNode* root)
{
	int count = 0; // �ѳ�� ���� ����

	// ���� ��ȸ �̿��Ͽ� ��� ���� Ȯ��

	push(root);
	while (top != -1) {
		root = pop();
		if (root != NULL) {
			push(root->right); 
			push(root->left); 
			
			count++; // �ѳ�� 1 �߰�
		}
	}

	printf("%d", count); // �ѳ�� ���� ���

}

int main()
{
	printf("������ ���� %f�Դϴ�.\n\n", evaluate(root));

	printf("�� ����� ���� : ");
	node_counter(root);
	printf("\n");

	return 0;
}
