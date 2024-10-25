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
	// 递归 先序遍历
	// 1. 确定参数和返回参数
	TreeNode* preorder(TreeNode* root, int val)
	{
		// 2. 终止条件
		if (root->val == val)
		{
			return root;
		}
		TreeNode* node = NULL;
		// 3. 单次递归处理
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
	// 迭代法
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
	// 不用任何辅助数据结构
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