#include <stdio.h>

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

int count = 0;

double evaluate(TreeNode* root)
{
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return root->data;

	else {
		double op1 = evaluate(root->left);
		double op2 = evaluate(root->right);

		printf("%f %c %f = ", op1, (char)root->data, op2);

		count++;

		switch ((char)root->data)
		{
		case '+': printf("%f\n", op1 + op2); return op1 + op2;
		case '-': printf("%f\n", op1 - op2);  return op1 - op2;
		case '*': printf("%f\n", op1 * op2); return op1 * op2;
		case '/': printf("%f\n", op1 / op2); return op1 / op2;
		}
	}
}

	int main()
{
	int count = 0;

	printf("수식의 값은 %f입니다.\n", evaluate(root));

	// printf("총 노드의 개수는 %d입니다\n."count + 1);

	return 0;
}
