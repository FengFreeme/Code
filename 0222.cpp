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
	// 层序遍历 实现
	int countNodes(TreeNode* root) 
	{
		int depth = 0;
		deque<TreeNode*> que;
		if (root == NULL)
			return 0;
		que.push_back(root);
		// 最后一层结点个数
		int LastNum;
		while (!que.empty())
		{
			depth++;
			int size = que.size();
			LastNum = size;
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
		int ans = pow(2, depth - 1) - 1 + LastNum;

		return ans;
	}
	*/
	int ans;
	// 先序遍历 递归 求最大深度以及相应结点数量
	int countNodes(TreeNode* root)
	{
		// 记录每一层结点数量
		vector<int> record;
		ans = 0;
		if (root == NULL)
			return 0;
		getDepth(root, 1, record);

		int result = pow(2, ans - 1) - 1 + record[ans - 1];

		return result;
	}
	// 1. 参数和返回参数
	void getDepth(TreeNode* cur, int depth, vector<int>& record)
	{
		// 3. 单次递归处理
		if (record.size() < depth)
			record.push_back(int(0));
		record[depth - 1]++;
		// depth 是当前结点的深度
		ans = ans > depth ? ans : depth;			// 中
		// 2. 终止条件
		if (cur->left == NULL && cur->right == NULL) 
			return;
		if (cur->left != NULL)
		{
			depth++;
			getDepth(cur->left, depth, record);		// 左
			depth--;
		}
		if (cur->right != NULL)
		{
			depth++;
			getDepth(cur->right, depth, record);	// 右
			depth--;
		}
		return;
	}
	// 利用二叉树性质
	// 分别递归左孩子，和右孩子
	// 递归到某一深度一定会有左孩子或者右孩子为满二叉树
	// 后序遍历
	int countNodes(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		int leftDepth = 0;
		int rightDepth = 0;
		while (left)
		{
			left = left->left;
			leftDepth++;
		}
		while (right)
		{
			right = right->right;
			rightDepth++;
		}
		if (leftDepth == rightDepth)
		{
			return pow(2, leftDepth + 1) - 1;
		}
		return countNodes(root->left) + countNodes(root->right) + 1;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	// TreeNode* node = root;
	// node->left = new TreeNode(2);
	// node->right = new TreeNode(3);
	// node->left->left = new TreeNode(4);
	// node->left->right = new TreeNode(5);
	// node->right->right = new TreeNode(7);

	Solution S;
	S.countNodes(root);

	return 0;
}