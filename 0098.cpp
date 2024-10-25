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
	// ������� 
	// ��������£�����Ķ����������ڵ����ֵ����������
	// 1. ȷ�������ͷ��ز���
	TreeNode* pre = NULL;
	bool isValidBST(TreeNode* root) 
	{
		// 2. ȷ����ֹ����
		if (root == NULL)
			return true;
		// 3. ���εݹ鴦��
		bool left = isValidBST(root->left);				// ��

		if (pre != NULL && pre->val >= root->val)		// ��
			return false;
		pre = root;

		bool right = isValidBST(root->right);			// ��

		return left && right;
	}
	*/
	// ������� ������
	bool isValidBST(TreeNode* root)
	{
		if (root == NULL)
			return true;
		stack<TreeNode*> st;
		st.push(root);
		TreeNode* pre = NULL;
		while (!st.empty())
		{
			TreeNode* node = st.top();
			// ����
			if (node != NULL)
			{
				st.pop();
				if (node->right != NULL)			// ��
					st.push(node->right);
				st.push(node);						// ��
				st.push(NULL);
				if (node->left != NULL)				// ��
					st.push(node->left);
			}
			// ����
			else
			{
				st.pop();
				node = st.top();
				st.pop();
				if (pre != NULL && pre->val >= node->val)
					return false;
				pre = node;
			}
		}
		return true;
	}
};

int main()
{
	TreeNode* root = new TreeNode(4);
	TreeNode* node = root;
	node->left = new TreeNode(2);
	node->right = new TreeNode(7);
	node->left->left = new TreeNode(1);
	node->left->right = new TreeNode(3);
	// node->right->left = new TreeNode(4);
	// node->right->right = new TreeNode(7);

	Solution S;
	S.isValidBST(root);

	return 0;
}