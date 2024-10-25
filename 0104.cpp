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
	int maxDepth(TreeNode* root) 
	{
		int depth = 0;
		depth = order(root, depth);

		return depth;
	}
	// 1. 确定参数和返回值
	int order(TreeNode* cur, int depth)
	{
		// 2. 终止条件
		if (cur == NULL)
			return depth;
		else
			depth++;
		// 3. 确定单层递归的逻辑
		int temp1 = order(cur->left, depth);
		int temp2 = order(cur->right, depth);
		depth = depth < temp1 ? temp1 : depth;
		depth = depth < temp2 ? temp2 : depth;
	}
	
	int maxDepth(TreeNode* root)
	{
		return getDepth(root);
	}
	// 后序遍历 递归
	int getDepth(TreeNode* node)
	{
		if (node == NULL)
			return 0;
		int leftDepth = getDepth(node->left);
		int rightDepth = getDepth(node->right);
		// 先求它的左子树的深度，再求右子树的深度
		// 最后取左右深度最大的数值 再+1 （加1是因为算上当前中间节点）就是目前节点为根节点的树的深度。
		int depth = 1 + max(leftDepth, rightDepth);

		return depth;
	}
	
	// 先中间结点加1后遍历左右结点
	// 先序遍历
	int ans;
	void getDepth(TreeNode* node, int depth)
	{
		ans = depth > ans ? depth : ans;		// 中
		if (node->left == NULL && node->right == NULL)
			return;
		if (node->left != NULL)					// 左
		{
			depth++;							// 深度+1
			getDepth(node->left, depth);
			depth--;							// 回溯 深度-1
		}
		if (node->right != NULL)				// 右
		{
			depth++;
			getDepth(node->right, depth);
			depth--;
		}
		return;
	}
	int maxDepth(TreeNode* root)
	{
		ans = 0;
		if (root == NULL)
			return ans;
		getDepth(root, 1);

		return ans;
	}
	*/
	// 层序遍历 迭代
	int maxDepth(TreeNode* root)
	{
		int ans = 0;
		deque<TreeNode*> que;
		if (root != NULL)
			que.push_back(root);
		while (!que.empty())
		{
			ans++;
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = que.front();
				que.pop_front();
				if (node->left != NULL)
					que.push_back(node->left);
				if (node->right != NULL)
					que.push_back(node->right);
			}
		}
		return ans;
	}
};


int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* node = root;
	// node->left = new TreeNode(9);
	node->right = new TreeNode(2);
	node->right->left = new TreeNode(3);
	// node->right->right = new TreeNode(7);

	Solution S;
	S.maxDepth(root);

	return 0;
}
