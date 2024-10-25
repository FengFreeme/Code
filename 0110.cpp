#include <iostream>
#include <vector>
#include <deque>
#include <stack>

using namespace std;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	/*
	bool isBalanced(TreeNode* root) 
	{
		if (GetHeight(root) == -1)
			return false;
		else
			return true;
	}
	// 后序遍历 递归
	// 1. 确定参数和返回参数
	int GetHeight(TreeNode* root)
	{
		// 2. 确定终止条件
		if (root == NULL)
			return 0;
		// 3. 单次递归
		int leftHeight = GetHeight(root->left);
		if (leftHeight == -1)
			return -1;
		int rightHeight = GetHeight(root->right);
		if (rightHeight == -1)
			return -1;

		if (abs(leftHeight - rightHeight) > 1)
			return -1;
		else
			// 以当前结点root为根节点的树的最大高度
			return 1 + max(leftHeight, rightHeight);
	}
	*/
	// 后序遍历统一迭代法 左右中
	int GetDepth(TreeNode* root)
	{
		int ans = 0;
		int depth = 0;
		stack<TreeNode*> st;
		if (root != NULL)
			st.push(root);
		while (!st.empty())
		{
			TreeNode* node = st.top();
			// 访问
			if (node != NULL)
			{
				st.pop();
				st.push(node);			// 中
				st.push(NULL);			// 加入标记空结点
				depth++;
				if (node->right != NULL)	// 右
					st.push(node->right);
				if (node->left != NULL)		// 左
					st.push(node->left);
			}
			// 处理
			else
			{
				st.pop();
				node = st.top();
				st.pop();
				depth--;
			}
			ans = ans > depth ? ans : depth;
		}
		return ans;
	}
	// 层序遍历
	bool isBalanced(TreeNode* root)
	{
		if (root == NULL)
			return false;
		deque<TreeNode*> que;
		que.push_back(root);
		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = que.front();
				que.pop_front();
				int leftDepth = GetDepth(node->left);
				int rightDepth = GetDepth(node->right);
				if (abs(leftDepth - rightDepth) > 1)
					return false;

				if (node->left != NULL)
					que.push_back(node->left);
				if (node->right != NULL)
					que.push_back(node->right);
			}
		}
		return true;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* node = root;
	node->left = new TreeNode(2);
	node->right = new TreeNode(3);
	node->left->left = new TreeNode(4);
	node->left->right = new TreeNode(5);
	// node->right->right = new TreeNode(7);

	Solution S;
	S.isBalanced(root);

	return 0;
}