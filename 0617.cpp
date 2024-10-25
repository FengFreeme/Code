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
	// 使用先序遍历
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
	{
		return traversal(root1, root2);
	}
	// 以第一个参数为主
	// 1. 确定参数和返回参数
	TreeNode* traversal(TreeNode* root1, TreeNode* root2)
	{
		// 2. 终止条件
		if (root1 == NULL && root2 == NULL)
			return NULL;
		else if (root1 != NULL && root2 == NULL)
			return root1;
		// 3. 单次递归
		if (root1 != NULL && root2 != NULL)
		{
			root1->val = root1->val + root2->val;
		}
		else if (root1 == NULL && root2 != NULL)
		{
			root1 = new TreeNode(root2->val);
		}
		
		root1->left = traversal(root1->left, root2->left);
		root1->right = traversal(root1->right, root2->right);

		return root1;
	}
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
	{
		if (root1 == NULL)
			return root2;
		if (root2 == NULL)
			return root1;
		root1->val = root1->val + root2->val;		// 中
		root1->left = mergeTrees(root1->left, root2->left);		// 左
		root1->right = mergeTrees(root1->right, root2->right);

		return root1;
	}
	*/
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
	{
		if (root1 == NULL)
			return root2;
		if (root2 == NULL)
			return root1;
		deque<TreeNode*> que;
		que.push_back(root1);
		que.push_back(root2);
		while (!que.empty())
		{
			TreeNode* cur1 = que.front();
			que.pop_front();
			TreeNode* cur2 = que.front();
			que.pop_front();
			cur1->val = cur1->val + cur2->val;
			if (cur1->left != NULL && cur2->left != NULL)
			{
				que.push_back(cur1->left);
				que.push_back(cur2->left);
			}
			if (cur1->right != NULL && cur2->right != NULL)
			{
				que.push_back(cur1->right);
				que.push_back(cur2->right);
			}
			// 没有必要处理
			if (cur1->left != NULL && cur2->left == NULL)
				;
			if (cur1->right != NULL && cur2->right == NULL)
				;
			if (cur1->left == NULL && cur2->left != NULL)
			{
				cur1->left = cur2->left;
			}
			if (cur1->right == NULL && cur2->right != NULL)
			{
				cur1->right = cur2->right;
			}
		}
		return root1;
	}
};

int main()
{
	TreeNode* root1 = new TreeNode(1);
	TreeNode* node = root1;
	node->left = new TreeNode(3);
	node->right = new TreeNode(2);
	node->left->left = new TreeNode(5);
	// node->left->right = new TreeNode(5);
	// node->right->left = new TreeNode(4);
	// node->right->right = new TreeNode(7);
	TreeNode* root2 = new TreeNode(2);
	node = root2;
	node->left = new TreeNode(1);
	node->right = new TreeNode(3);
	node->left->right = new TreeNode(4);
	node->right->right = new TreeNode(7);
	Solution S;
	S.mergeTrees(root1, root2);

	return 0;
}