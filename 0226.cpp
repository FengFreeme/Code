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
	// 递归
	TreeNode* invertTree(TreeNode* root) 
	{
		Reverse(root);

		return root;
	}
	// 1. 递归参数和返回值 应该是先序遍历
	void Reverse(TreeNode* cur)
	{
		// 2. 终止条件
		if (cur == NULL)
			return;
		// 3. 单次递归处理
		if (cur->left != NULL || cur->right != NULL)		// 中
		{
			TreeNode* temp = cur->left;						
			cur->left = cur->right;
			cur->right = temp;
		}
		Reverse(cur->left);									// 左
		Reverse(cur->right);								// 右
	}
	// 层序遍历实现
	TreeNode* invertTree(TreeNode* root)
	{
		deque<TreeNode*> que;
		if (root != NULL)
			que.push_back(root);
		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = que.front();
				que.pop_front();
				TreeNode* temp = node->right;
				node->right = node->left;
				node->left = temp;

				if (node->left != NULL)
					que.push_back(node->left);
				if (node->right != NULL)
					que.push_back(node->right);
			}
		}
		return root;
	}
	// 迭代法实现（统一）先序遍历 空结点作为标记
	TreeNode* invertTree(TreeNode* root)
	{
		stack<TreeNode*> st;
		if (root != NULL)
			st.push(root);
		while (!st.empty())
		{
			TreeNode* node = st.top();
			// 还未访问
			if (node != NULL)
			{
				st.pop();
				if (node->right != NULL)		// 右
					st.push(node->right);
				if (node->left != NULL)
					st.push(node->left);
				st.push(node);
				st.push(NULL);
			}
			// 已访问过 开始处理
			else
			{
				st.pop();
				node = st.top();
				st.pop();
				swap(node->left, node->right);
			}
		}
		return root;
	}
};