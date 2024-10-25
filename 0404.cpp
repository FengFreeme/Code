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
	// 递归 先序遍历 中左右
	int sum = 0;
	int sumOfLeftLeaves(TreeNode* root) 
	{
		order(root);

		return sum;
	}
	// 1. 确定参数和返回参数
	void order(TreeNode* root)
	{
		// 2. 终止条件
		if (root == NULL)
			return;
		// 3. 单次递归处理
		// 左叶子
		// 中
		if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
		{
			sum += root->left->val;
		}
		if (root->left != NULL)
			order(root->left);
		if (root->right != NULL)
			order(root->right);

		return;
	}
	
	// 统一迭代 先序遍历 中左右
	int sumOfLeftLeaves(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		stack<TreeNode*> st;
		st.push(root);
		int ans = 0;
		while (!st.empty())
		{
			TreeNode* node = st.top();
			// 访问
			if (node != NULL)
			{
				st.pop();
				if (node->right != NULL)
					st.push(node->right);
				if (node->left != NULL)
					st.push(node->left);
				st.push(node);
				st.push(NULL);
			}
			else
			{
				st.pop();
				node = st.top();
				st.pop();
				if (node->left != NULL && node->left->left == NULL && node->left->right == NULL)
					ans += node->left->val;
			}
		}
		return ans;
	}
	*/
	// 常规迭代法
	int sumOfLeftLeaves(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int ans = 0;
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();
			if (node->left != NULL && node->left->left == NULL && node->left->right == NULL)
				ans += node->left->val;
			if (node->right != NULL)
				st.push(node->right);
			if (node->left != NULL)
				st.push(node->left);
		}
		return ans;
	}
	// 后序遍历 递归
	int sumOfLeftLeaves(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return 0;
		int leftValue = sumOfLeftLeaves(root->left);	// 左
		if (root->left && !root->left->left && !root->left->right)
			leftValue = root->left->val;
		int rightValue = sumOfLeftLeaves(root->right);	// 右
		int sum = leftValue + rightValue;

		return sum;
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
	S.sumOfLeftLeaves(root);

	return 0;
}