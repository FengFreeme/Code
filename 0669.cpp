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
	// 先序遍历 删除结点按照二叉搜索树的规则
	// 1. 确定参数和返回参数
	// TreeNode* pre = NULL;
	TreeNode* trimBST1(TreeNode* root, int low, int high) 
	{
		// 2. 终止条件
		if (root == NULL)
			return NULL;
		// 寻找符合区间[low, high]的节点
		if (root->val < low)
		{
			TreeNode* right = trimBST(root->right, low, high);

			return right;
		}
		if (root->val > high)
		{
			TreeNode* left = trimBST(root->left, low, high);

			return left;
		}
		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);

		return root;
	}
	TreeNode* trimBST(TreeNode* root, int low, int high)
	{
		if (root == NULL)
			return NULL;

		// 处理头结点，将root移动到范围内
		while (root != NULL && (root->val < low || root->val > high))
		{
			if (root->val < low)
				root = root->right;
			else
				root = root->left;
		}
		TreeNode* cur = root;
		// 此时root已经在范围内 处理左孩子
		while (cur != NULL)
		{
			while (cur->left && cur->left->val < low)
			{
				cur->left = cur->left->right;
			}
			cur = cur->left;
		}

		cur = root;
		// 此时root已经在范围内 处理右孩子
		while (cur != NULL)
		{
			while (cur->right != NULL && cur->right->val > high)
			{
				cur->right = cur->right->left;
			}
			cur = cur->right;
		}
		return root;
	}
	
};

int main()
{
	TreeNode* root = new TreeNode(3);
	TreeNode* node = root;
	node->left = new TreeNode(0);
	node->right = new TreeNode(4);
	// TreeNode* left = node->left;
	// TreeNode* right = node->right;
	// node->left->left = new TreeNode(2);
	node->left->right = new TreeNode(2);
	// node->right->left = new TreeNode(7);
	// node->right->right = new TreeNode(7);
	node->left->right->left = new TreeNode(1);
	// node->left->right->right = new TreeNode(5);
	// TreeNode* left = node->left->right->left;
	// TreeNode* right = node->left->right->right;
	Solution S;
	S.trimBST(root, 1, 3);

	return 0;
}