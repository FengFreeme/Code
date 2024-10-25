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
	// 1. 参数和返回参数
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		// 2. 终止条件
		if (root == p || root == q || root == NULL)
			return root;
		// 3. 单次递归处理
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		if (left != NULL && right != NULL)
			return root;
		else if (left != NULL && right == NULL)
			return left;
		else if (left == NULL && right != NULL)
			return right;
		else
			return NULL;
	}
	*/
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		return traversal(root, p, q);
	}
	// 1. 确定参数和返回参数
	TreeNode* traversal(TreeNode* cur, TreeNode* p, TreeNode* q)
	{
		// 2. 终止条件
		if (cur == NULL)
			return NULL;
		// 3. 单次递归处理
		// 搜索一条边的写法
		if (cur->val > p->val && cur->val > q->val)
		{
			TreeNode* left = traversal(cur->left, p, q);
			if (left != NULL)
				return left;
		}
		if (cur->val < p->val && cur->val < q->val)
		{
			TreeNode* right = traversal(cur->right, p, q);
			if (right != NULL)
				return right;
		}

		return cur;
	}
};

int main()
{
	TreeNode* root = new TreeNode(6);
	TreeNode* node = root;
	node->left = new TreeNode(2);
	node->right = new TreeNode(8);
	// TreeNode* left = node->left;
	// TreeNode* right = node->right;
	node->left->left = new TreeNode(0);
	TreeNode* left = node->left->left;
	node->left->right = new TreeNode(4);
	node->right->left = new TreeNode(7);
	node->right->right = new TreeNode(9);
	TreeNode* right = node->right->right;
	node->left->right->left = new TreeNode(3);
	node->left->right->right = new TreeNode(5);
	// TreeNode* left = node->left->right->left;
	// TreeNode* right = node->left->right->right;
	Solution S;
	S.lowestCommonAncestor(root, left, right);

	return 0;
}