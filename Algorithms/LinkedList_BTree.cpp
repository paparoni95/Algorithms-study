#include <iostream>
#include <cstdlib>
using namespace std;

// 이진트리
typedef struct Tree
{
	int data;
	struct Tree* left;
	struct Tree* right;
}BTreeNode;

// 이진 트리 노드를 생성해서 주소 값을 반환한다.
BTreeNode* MakeBTreeNode()
{
	BTreeNode* tree_node = (BTreeNode*)malloc(sizeof(BTreeNode));
	tree_node->left = NULL;
	tree_node->right = NULL;
	return tree_node;
}

// 해당 트리를 소멸
void DeleteTree(BTreeNode* bt)
{
	if (bt == NULL)
		return;

	DeleteTree(bt->left);
	DeleteTree(bt->right);

	cout << "free data: " << bt->data << endl;
	free(bt);
}

// 왼쪽 서브트리 주소 반환
BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}

// 오른쪽 서브트리 주소 반환
BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

// 왼쪽 서브트리 이어 붙이기
void MakeLeftSubTree(BTreeNode* root, BTreeNode* sub)
{
	if (root->left != NULL)
	{
		DeleteTree(root->left);
	}

	root->left = sub;
}

// 오른쪽 서브트리 이어 붙이기.
void MakeRightSubTree(BTreeNode* root, BTreeNode* sub)
{
	if (root->right != NULL)
	{
		DeleteTree(root->right);
	}

	root->right = sub;
}

// 노드에 저장된 데이터를 반환한다.
int GetData(BTreeNode* bt)
{
	return bt->data;
}

// 노드에 data로 전달된 값을 저장한다.
void SetData(BTreeNode* bt, int data)
{
	bt->data = data;
}

// 중위순회
void inorder_traversal(BTreeNode* bt)
{
	if (bt != NULL)
	{
		inorder_traversal(bt->left);
		cout << bt->data << ' ';
		inorder_traversal(bt->right);
	}
}

// 전위순회
void preorder_traversal(BTreeNode* bt)
{
	if (bt != NULL)
	{
		cout << bt->data << ' ';
		preorder_traversal(bt->left);
		preorder_traversal(bt->right);
	}
}

// 후위순회
void postorder_traversal(BTreeNode* bt)
{
	if (bt != NULL)
	{
		postorder_traversal(bt->left);
		postorder_traversal(bt->right);
		cout << bt->data << ' ';
	}
}

int main()
{
	BTreeNode* root = MakeBTreeNode();
	SetData(root, 0);
	BTreeNode* node1 = MakeBTreeNode();
	SetData(node1, 1);
	BTreeNode* node2 = MakeBTreeNode();
	SetData(node2, 2);
	BTreeNode* node3 = MakeBTreeNode();
	SetData(node3, 3);
	BTreeNode* node4 = MakeBTreeNode();
	SetData(node4, 4);

	MakeLeftSubTree(root, node1);
	MakeRightSubTree(root, node2);
	MakeLeftSubTree(node1, node3);
	MakeRightSubTree(node1, node4);

	cout << "중위 순회: "; inorder_traversal(root); cout << endl;
	cout << "전위 순회: "; preorder_traversal(root); cout << endl;
	cout << "후위 순회 : "; postorder_traversal(root); cout << endl;

	BTreeNode* node5 = MakeBTreeNode();
	BTreeNode* node6 = MakeBTreeNode();
	BTreeNode* node7 = MakeBTreeNode();
	SetData(node5, 7);
	SetData(node6, 8);
	SetData(node7, 9);

	MakeLeftSubTree(node5, node6);
	MakeRightSubTree(node5, node7);

	// 기존의 root의 왼쪽 서브트리를 바꾼다.
	MakeLeftSubTree(root, node5);

	cout << "중위 순회: "; inorder_traversal(root); cout << endl;
	cout << "전위 순회: "; preorder_traversal(root); cout << endl;
	cout << "후위 순회 : "; postorder_traversal(root); cout << endl;
	return 0;
}