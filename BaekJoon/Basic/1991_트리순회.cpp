#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct tree
{
	char data;
	struct tree* left;
	struct tree* right;
}BTree;

// 노드생성
BTree* MakeBTreeNode(char data)
{
	BTree* new_node = (BTree*)malloc(sizeof(BTree));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->data = data;
	return new_node;
}

void MakeLeftSubTree(BTree* bt, BTree* sub)
{
	bt->left = sub;
}

void MakeRightSubTree(BTree* bt, BTree* sub)
{
	bt->right = sub;
}

void preorder_traversal(BTree* bt)
{
	if (bt == NULL)
		return;

	cout << bt->data;
	preorder_traversal(bt->left);
	preorder_traversal(bt->right);
}

void inorder_traversal(BTree* bt)
{
	if (bt == NULL)
		return;

	inorder_traversal(bt->left);
	cout << bt->data;
	inorder_traversal(bt->right);
}

void postorder_traversal(BTree* bt)
{
	if (bt == NULL)
		return;

	postorder_traversal(bt->left);
	postorder_traversal(bt->right);
	cout << bt->data;
}

int main()
{
	int n;
	cin >> n;
	BTree* tree[27];
	for (int i = 0; i < n; i++)
	{
		tree[i] = MakeBTreeNode('A' + i);
	}
	

	for (int i = 0; i < n; i++)
	{
		char ch1, ch2, ch3;
		cin >> ch1 >> ch2 >> ch3;

		if (ch2 != '.')
		{
			MakeLeftSubTree(tree[ch1 - 'A'], tree[ch2 - 'A']);
		}

		if (ch3 != '.')
		{
			MakeRightSubTree(tree[ch1 - 'A'], tree[ch3 - 'A']);
		}
	}

	preorder_traversal(tree[0]); cout << endl;
	inorder_traversal(tree[0]); cout << endl;
	postorder_traversal(tree[0]); cout << endl;
	return 0;
}