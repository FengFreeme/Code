#include <iostream>
#include <vector>
#include <deque>
#include <stack>

using namespace std;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	/*
	bool isBalanced(TreeNode* root) 
	{
		if (GetHeight(root) == -1)
			return false;
		else
			return true;
	}
	// ������� �ݹ�
	// 1. ȷ�������ͷ��ز���
	int GetHeight(TreeNode* root)
	{
		// 2. ȷ����ֹ����
		if (root == NULL)
			return 0;
		// 3. ���εݹ�
		int leftHeight = GetHeight(root->left);
		if (leftHeight == -1)
			return -1;
		int rightHeight = GetHeight(root->right);
		if (rightHeight == -1)
			return -1;

		if (abs(leftHeight - rightHeight) > 1)
			return -1;
		else
			// �Ե�ǰ���rootΪ���ڵ���������߶�
			return 1 + max(leftHeight, rightHeight);
	}
	*/
	// �������ͳһ������ ������
	int GetDepth(TreeNode* root)
	{
		int ans = 0;
		int depth = 0;
		stack<TreeNode*> st;
		if (root != NULL)
			st.push(root);
		while (!st.empty())
		{
			TreeNode* node = st.top();
			// ����
			if (node != NULL)
			{
				st.pop();
				st.push(node);			// ��
				st.push(NULL);			// �����ǿս��
				depth++;
				if (node->right != NULL)	// ��
					st.push(node->right);
				if (node->left != NULL)		// ��
					st.push(node->left);
			}
			// ����
			else
			{
				st.pop();
				node = st.top();
				st.pop();
				depth--;
			}
			ans = ans > depth ? ans : depth;
		}
		return ans;
	}
	// �������
	bool isBalanced(TreeNode* root)
	{
		if (root == NULL)
			return false;
		deque<TreeNode*> que;
		que.push_back(root);
		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = que.front();
				que.pop_front();
				int leftDepth = GetDepth(node->left);
				int rightDepth = GetDepth(node->right);
				if (abs(leftDepth - rightDepth) > 1)
					return false;

				if (node->left != NULL)
					que.push_back(node->left);
				if (node->right != NULL)
					que.push_back(node->right);
			}
		}
		return true;
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
	S.isBalanced(root);

	return 0;
}