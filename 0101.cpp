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
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	bool isSymmetric(TreeNode* root) 
	{
		bool ans = false;
		if (root != NULL)
			ans = mirror(root->left, root->right);
		return ans;
	}
	// ������ ������ ������ ������
	// 1. ȷ�������ͷ��ز���
	bool mirror(TreeNode* left, TreeNode* right)
	{
		// 2. ��ֹ����
		if (left == NULL && right == NULL)
			return true;
		else if (left == NULL && right != NULL)
			return false;
		else if (left != NULL && right == NULL)
			return false;
		// 3. ���εݹ鴦��
		if (left->val == right->val)
		{
			return mirror(left->left, right->right) && mirror(left->right, right->left);
		}
		else
			return false;
	}
};

int main()
{
	TreeNode* root = new TreeNode(2);
	TreeNode* node = root;
	node->left = new TreeNode(3);
	node->right = new TreeNode(3);
	TreeNode* node1 = node->left;
	TreeNode* node2 = node->right;
	node1->left = new TreeNode(4);
	node1->right = new TreeNode(5);
	node2->left = new TreeNode(5);

	Solution S;
	S.isSymmetric(root);

	return 0;
}