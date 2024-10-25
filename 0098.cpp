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
	// 中序遍历 
	// 中序遍历下，输出的二叉搜索树节点的数值是有序序列
	// 1. 确定参数和返回参数
	TreeNode* pre = NULL;
	bool isValidBST(TreeNode* root) 
	{
		// 2. 确定终止条件
		if (root == NULL)
			return true;
		// 3. 单次递归处理
		bool left = isValidBST(root->left);				// 左

		if (pre != NULL && pre->val >= root->val)		// 中
			return false;
		pre = root;

		bool right = isValidBST(root->right);			// 右

		return left && right;
	}
	*/
	// 中序遍历 迭代法
	bool isValidBST(TreeNode* root)
	{
		if (root == NULL)
			return true;
		stack<TreeNode*> st;
		st.push(root);
		TreeNode* pre = NULL;
		while (!st.empty())
		{
			TreeNode* node = st.top();
			// 访问
			if (node != NULL)
			{
				st.pop();
				if (node->right != NULL)			// 右
					st.push(node->right);
				st.push(node);						// 中
				st.push(NULL);
				if (node->left != NULL)				// 左
					st.push(node->left);
			}
			// 处理
			else
			{
				st.pop();
				node = st.top();
				st.pop();
				if (pre != NULL && pre->val >= node->val)
					return false;
				pre = node;
			}
		}
		return true;
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
	S.isValidBST(root);

	return 0;
}