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
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	// �ݹ�
	TreeNode* invertTree(TreeNode* root) 
	{
		Reverse(root);

		return root;
	}
	// 1. �ݹ�����ͷ���ֵ Ӧ�����������
	void Reverse(TreeNode* cur)
	{
		// 2. ��ֹ����
		if (cur == NULL)
			return;
		// 3. ���εݹ鴦��
		if (cur->left != NULL || cur->right != NULL)		// ��
		{
			TreeNode* temp = cur->left;						
			cur->left = cur->right;
			cur->right = temp;
		}
		Reverse(cur->left);									// ��
		Reverse(cur->right);								// ��
	}
	// �������ʵ��
	TreeNode* invertTree(TreeNode* root)
	{
		deque<TreeNode*> que;
		if (root != NULL)
			que.push_back(root);
		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = que.front();
				que.pop_front();
				TreeNode* temp = node->right;
				node->right = node->left;
				node->left = temp;

				if (node->left != NULL)
					que.push_back(node->left);
				if (node->right != NULL)
					que.push_back(node->right);
			}
		}
		return root;
	}
	// ������ʵ�֣�ͳһ��������� �ս����Ϊ���
	TreeNode* invertTree(TreeNode* root)
	{
		stack<TreeNode*> st;
		if (root != NULL)
			st.push(root);
		while (!st.empty())
		{
			TreeNode* node = st.top();
			// ��δ����
			if (node != NULL)
			{
				st.pop();
				if (node->right != NULL)		// ��
					st.push(node->right);
				if (node->left != NULL)
					st.push(node->left);
				st.push(node);
				st.push(NULL);
			}
			// �ѷ��ʹ� ��ʼ����
			else
			{
				st.pop();
				node = st.top();
				st.pop();
				swap(node->left, node->right);
			}
		}
		return root;
	}
};