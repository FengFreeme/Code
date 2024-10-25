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

	// 递归
	// 1. 确定参数和返回参数
	// TreeNode* pre = NULL;
	TreeNode* deleteNode(TreeNode* root, int key) 
	{
		// 2. 终止条件
		if (root == NULL)
			return NULL;
		if (root->val == key)
		{
			if (root->left != NULL && root->right != NULL)
			{
				TreeNode* left = root->left;
				TreeNode* right = root->right;
				TreeNode* temp = root;
				TreeNode* cur = right;
				while (cur->left != NULL)
				{
					cur = cur->left;
				}
				cur->left = left->right;
				left->right = right;
					
				root = left;
				delete temp;
			}
			else if (root->left != NULL && root->right == NULL)
			{
				TreeNode* temp = root;
				root = root->left;
				delete temp;
			}
			else if (root->left == NULL && root->right != NULL)
			{
				TreeNode* temp = root;
				root = root->right;
				delete temp;
			}
			else
			{
				TreeNode* temp = root;
				root = NULL;
				delete temp;
			}
			return root;
		}
		// 上一层就要用 root->left 或者 root->right接住
		if (root->val > key)
		{
			root->left = deleteNode(root->left, key);
		}

		if (root->val < key)
		{
			root->right = deleteNode(root->right, key);
		}
		return root;
	}
	// 迭代法
	TreeNode* deleteNode1(TreeNode* root, int key)
	{
		if (root == NULL)
			return NULL;
		TreeNode* cur = root;
		TreeNode* pre = NULL;
		while (cur != NULL)
		{
			if (cur->val > key)
			{
				pre = cur;
				cur = cur->left;
			}
			else if (cur->val < key)
			{
				pre = cur;
				cur = cur->right;
			}
			else
			{
				if (cur->left != NULL && cur->right != NULL)
				{
					TreeNode* left = cur->left;
					TreeNode* right = cur->right;
					TreeNode* temp = cur;
					if (pre != NULL)
					{
						if (pre->val > key)
							pre->left = left;
						else
							pre->right = left;
					}
					TreeNode* node = right;
					while (node->left != NULL)
					{
						node = node->left;
					}
					node->left = left->right;
					left->right = right;

					cur = left;
					delete temp;
				}
				else if (cur->left != NULL && cur->right == NULL)
				{
					if (pre != NULL)
					{
						if (pre->val > key)
							pre->left = cur->left;
						else
							pre->right = cur->left;
					}

					TreeNode* temp = cur;
					cur = cur->left;
					delete temp;
				}
				else if (cur->left == NULL && cur->right != NULL)
				{
					if (pre != NULL)
					{
						if (pre->val > key)
							pre->left = cur->right;
						else
							pre->right = cur->right;
					}

					TreeNode* temp = cur;
					cur = cur->right;
					delete temp;
				}
				else
				{
					if (pre != NULL)
					{
						if (pre->val > key)
							pre->left = NULL;
						else
							pre->right = NULL;
					}
					TreeNode* temp = cur;
					cur = NULL;
					delete temp;
				}
				if (pre != NULL)
					return root;
				else
					return cur;
			}
		}
		return root;
	}
};

int main()
{
	TreeNode* root = new TreeNode(5);
	TreeNode* node = root;
	node->left = new TreeNode(3);
	node->right = new TreeNode(6);
	// TreeNode* left = node->left;
	// TreeNode* right = node->right;
	node->left->left = new TreeNode(2);
	node->left->right = new TreeNode(4);
	// node->right->left = new TreeNode(7);
	node->right->right = new TreeNode(7);
	// node->left->right->left = new TreeNode(3);
	// node->left->right->right = new TreeNode(5);
	// TreeNode* left = node->left->right->left;
	// TreeNode* right = node->left->right->right;
	Solution S;
	S.deleteNode(root, 7);

	return 0;
}