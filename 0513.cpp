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
	// 全局变量
	int maxDepth = INT_MIN;
	int ans;
	int findBottomLeftValue(TreeNode* root) 
	{
		traversal(root, 1);

		return ans;
	}
	// 使用先序遍历保证左优先
	// 保证优先左边搜索，然后记录深度最大的叶子节点，此时就是树的最后一行最左边的值
	// 1. 确定参数和返回参数
	void traversal(TreeNode* root, int depth)
	{
		// 2. 终止条件 左优先
		if (root->left == NULL && root->right == NULL)
		{
			// 只有在深度更新时才会将结果更新为最左边的值
			if(depth > maxDepth)
			{
				maxDepth = depth;
				ans = root->val;
			}
			return;
		}
		// 3. 单次递归
										// 中
		if (root->left != NULL)			// 左
		{
			depth++;
			traversal(root->left, depth);
			depth--;
		}
		if (root->right != NULL)		// 右
		{
			depth++;
			traversal(root->right, depth);
			depth--;
		}
		
		return;
	}
	// 层序遍历
	int findBottomLeftValue(TreeNode* root)
	{
		deque<TreeNode*> que;
		que.push_back(root);
		int ans;
		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = que.front();
				if (i == 0)
					ans = node->val;
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
	node->left = new TreeNode(2);
	node->right = new TreeNode(3);
	node->left->left = new TreeNode(4);
	node->left->right = new TreeNode(5);
	// node->right->left = new TreeNode(4);
	// node->right->right = new TreeNode(7);

	Solution S;
	S.findBottomLeftValue(root);

	return 0;
}