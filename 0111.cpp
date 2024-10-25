#include <iostream>
#include <vector>
#include <deque>

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
	// 层序遍历 队列迭代
	int minDepth(TreeNode* root) 
	{
		if (root == NULL)
			return 0;
		int depth = 0;
		deque<TreeNode*> que;
		que.push_back(root);
		while (!que.empty())
		{
			int size = que.size();
			// 记录最小深度
			depth++;
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = que.front();
				que.pop_front();
				if (node->left == NULL && node->right == NULL)
					return depth;
				if (node->left != NULL)
					que.push_back(node->left);
				if (node->right != NULL)
					que.push_back(node->right);
				
			}
		}
		return depth;
	}
	
	// 递归 后序遍历 一般是求高度
	int minDepth(TreeNode* root)
	{
		return getDepth(root);
	}

	int getDepth(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int leftDepth = getDepth(root->left);
		int rightDepth = getDepth(root->right);

		if (root->left == NULL && root->right != NULL)
			return 1 + rightDepth;
		else if (root->left != NULL && root->right == NULL)
			return 1 + leftDepth;
		else
			return 1 + min(leftDepth, rightDepth);
	}
	*/
	int ans;
	int minDepth(TreeNode* root)
	{
		ans = INT_MAX;
		if (root == NULL)
			return 0;
		getDepth(root, 1);

		return ans;
	}
	// 先序遍历 递归
	void getDepth(TreeNode* root, int depth)
	{
		if(root->left == NULL && root->right == NULL)	// 中
			ans = ans > depth ? depth : ans;		
		if (root->left != NULL)							// 左
		{
			depth++;
			getDepth(root->left, depth);
			depth--;
		}
		if (root->right != NULL)						// 右
		{
			depth++;
			getDepth(root->right, depth);
			depth--;
		}
		return;
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
	S.minDepth(root);

	return 0;
}
