#include <iostream>
#include <vector>
#include <deque>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	
	TreeNode* searchBST(TreeNode* root, int val) 
	{
		return preorder(root, val);
	}
	/*
	// �ݹ� �������
	// 1. ȷ�������ͷ��ز���
	TreeNode* preorder(TreeNode* root, int val)
	{
		// 2. ��ֹ����
		if (root->val == val)
		{
			return root;
		}
		TreeNode* node = NULL;
		// 3. ���εݹ鴦��
		if (root->val > val && root->left != NULL)
		{
			node = preorder(root->left, val);
		}
		else if (root->val < val && root->right != NULL)
		{
			node = preorder(root->right, val);
		}
		if (node != NULL)
			return node;
		else
			return NULL;
	}
	*/
	// ������
	TreeNode* preorder(TreeNode* root, int val)
	{
		
		if (root == NULL)
			return root;
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();
			if (node->val < val && node->right != NULL)
				st.push(node->right);
			else if (node->val > val && node->left != NULL)
				st.push(node->left);
			else if(node->val == val)
				return node;
		}
		return NULL;
	}
	// �����κθ������ݽṹ
	TreeNode* searchBST(TreeNode* root, int val)
	{
		while (root != NULL)
		{
			if (root->val > val)
				root = root->left;
			else if (root->val < val)
				root = root->right;
			else if (root->val == val)
				return root;
		}
		return NULL;
	}
};

int main()
{
	TreeNode* root = new TreeNode(4);
	TreeNode* node = root;
	node->left = new TreeNode(2);
	node->right = new TreeNode(7);
	node->left->left = new TreeNode(1);
	node->left->right = new TreeNode(3);
	// node->right->left = new TreeNode(4);
	// node->right->right = new TreeNode(7);

	Solution S;
	S.searchBST(root, 0);

	return 0;
}