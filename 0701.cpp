#include <iostream>
#include <vector>
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
	/*
	// 1. ȷ�������ͷ��ز���
	TreeNode* insertIntoBST(TreeNode* root, int val) 
	{
		// 2. ȷ����ֹ����
		if (root == NULL)
		{
			root = new TreeNode(val);

			return root;
		}
		// 3. ���εݹ鴦��
		if (root->val > val)
		{
			TreeNode* left = insertIntoBST(root->left, val);
			root->left = left;

			return root;
		}
		if (root->val < val)
		{
			TreeNode* right = insertIntoBST(root->right, val);
			root->right = right;

			return root;
		}
		return root;
	}
	*/
	// ������
	TreeNode* insertIntoBST(TreeNode* root, int val)
	{
		if (root == NULL)
		{
			root = new TreeNode(val);

			return root;
		}
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();
			if (node->val > val && node->left == NULL)
			{
				node->left = new TreeNode(val);
			}
			if (node->val < val && node->right == NULL)
			{
				node->right = new TreeNode(val);
			}
			if (node->val > val && node->left != NULL)
			{
				st.push(node->left);
			}
			if (node->val < val && node->right != NULL)
			{
				st.push(node->right);
			}
		}
		return root;
	}
	// ������ ���ø������ݽṹ
	TreeNode* insertIntoBST(TreeNode* root, int val)
	{
		if (root == NULL)
		{
			root = new TreeNode(val);

			return root;
		}
		TreeNode* cur = root;
		// ��¼��һ���ڵ�
		TreeNode* parent = root;
		while (cur != NULL)
		{
			parent = cur;
			if (cur->val > val)
				cur = cur->left;
			else
				cur = cur->right;
		}
		TreeNode* node = new TreeNode(val);
		if (val < parent->val)
			parent->left = node;
		else
			parent->right = node;

		return root;
	}
};

int main()
{
	TreeNode* root = new TreeNode(4);
	TreeNode* node = root;
	node->left = new TreeNode(2);
	node->right = new TreeNode(7);
	// TreeNode* left = node->left;
	// TreeNode* right = node->right;
	node->left->left = new TreeNode(1);
	node->left->right = new TreeNode(3);
	// node->right->left = new TreeNode(7);
	// node->right->right = new TreeNode(9);
	// node->left->right->left = new TreeNode(3);
	// node->left->right->right = new TreeNode(5);
	// TreeNode* left = node->left->right->left;
	// TreeNode* right = node->left->right->right;
	Solution S;
	S.insertIntoBST(root, 5);

	return 0;
}