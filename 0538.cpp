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
	// 递归 反中序遍历
	// 1. 确定参数和返回参数
	TreeNode* pre = NULL;
	TreeNode* convertBST(TreeNode* root) 
	{
		// 2. 终止条件
		if (root == NULL)
			return NULL;

		// 3. 单次递归处理 右中左
		root->right = convertBST(root->right);
		if (pre != NULL)
		{
			root->val = root->val + pre->val;
		}
		pre = root;
		root->left = convertBST(root->left);

		return root;
	}
	*/
	TreeNode* convertBST(TreeNode* root)
	{
		if (root == NULL)
			return NULL;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		TreeNode* pre = NULL;
		while (cur != NULL || !st.empty())
		{
			if (cur != NULL)
			{
				st.push(cur);
				cur = cur->right;		// 右
			}
			else
			{
				cur = st.top();			// 中
				st.pop();
				if (pre != NULL)
					cur->val = cur->val + pre->val;
				pre = cur;
				cur = cur->left;		// 左
			}
		}
		return root;
	}
};

int main()
{
	TreeNode* root = new TreeNode(4);
	TreeNode* node = root;
	node->left = new TreeNode(1);
	node->right = new TreeNode(6);
	// TreeNode* left = node->left;
	// TreeNode* right = node->right;
	node->left->left = new TreeNode(0);
	node->left->right = new TreeNode(2);
	node->right->left = new TreeNode(5);
	node->right->right = new TreeNode(7);
	node->right->right->right = new TreeNode(8);
	// node->left->right->left = new TreeNode(1);
	node->left->right->right = new TreeNode(3);
	// TreeNode* left = node->left->right->left;
	// TreeNode* right = node->left->right->right;
	Solution S;
	S.convertBST(root);

	return 0;
}