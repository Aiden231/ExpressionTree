#include <stdio.h>

// 트리노드 구조체
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
	if (root == NULL) return 0; // 비어있을 경우에는 리턴
	if (root->left == NULL && root->right == NULL) return root->data; // 단일 노드일 경우에는 연산자임으로 data에 들어가 있는 연산자 리턴

	else {
		double op1 = evaluate(root->left); // 왼쪽 자식 = op1
		double op2 = evaluate(root->right); // 오른쪽 자식 = op2

		printf("%f %c %f = ", op1, (char)root->data, op2); // 계산 식 출력

		switch ((char)root->data) // 사칙연산 계산 후 리턴
		{
		case '+': printf("%f\n", op1 + op2); return op1 + op2;
		case '-': printf("%f\n", op1 - op2);  return op1 - op2;
		case '*': printf("%f\n", op1 * op2); return op1 * op2;
		case '/': printf("%f\n", op1 / op2); return op1 / op2;
		}
	}
}

// 반복적 방법으로 총 노드의 개수 세기

// // 스택 생성
#define SIZE 100
int top = -1;
TreeNode* stack[SIZE];

// 삽입 함수
void push(TreeNode* p)
{
	if (top < SIZE - 1) {
		stack[++top] = p;
	}
}

// 삭제 함수
TreeNode* pop()
{
	TreeNode* p = NULL;
	if (top >= 0) {
		p = stack[top--];
	}
	return p;
}

// 노드 카운터 함수
void node_counter(TreeNode* root)
{
	int count = 0; // 총노드 개수 변수

	// 전위 순회 이용하여 노드 개수 확인

	push(root);
	while (top != -1) {
		root = pop();
		if (root != NULL) {
			push(root->right); 
			push(root->left); 
			
			count++; // 총노드 1 추가
		}
	}

	printf("%d", count); // 총노드 개수 출력

}

int main()
{
	printf("수식의 값은 %f입니다.\n\n", evaluate(root));

	printf("총 노드의 개수 : ");
	node_counter(root);
	printf("\n");

	return 0;
}
