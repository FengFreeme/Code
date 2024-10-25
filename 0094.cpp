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
	vector<int> inorderTraversal(TreeNode* root) 
	{
		vector<int> ans;
		traversal(root, ans);

		return ans;
	}

	void traversal(TreeNode* root, vector<int>& ans)
	{
		if (root == NULL)
			return;
		traversal(root->left, ans);
		ans.push_back(root->val);
		traversal(root->right, ans);
	}
	// ������� �ǵݹ� ע�⴦��˳��ͷ���˳��һ��
	vector<int> inorderTraversal(TreeNode* root)
	{
		stack<TreeNode*> st;
		vector<int> ans;
		if (root == NULL)
			return ans;
		// st.push(root);
		TreeNode* cur = root;
		while (cur != NULL || !st.empty())
		{
			if (cur != NULL)
			{
				st.push(cur);
				cur = cur->left;			// ��
			}
			else
			{
				cur = st.top();
				ans.push_back(cur->val);	// ��
				st.pop();
				cur = cur->right;			// ��
			}
		}
		return ans;
	}
	// ������� ͳһ������� ��һ�ֱ�Ƿ�
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> ans;
		stack<TreeNode*> st;
		if (root != NULL)
			st.push(root);
		while (!st.empty())
		{
			TreeNode* node = st.top();
			if (node != NULL)
			{
				st.pop();		// ���ýڵ㵯���������ظ�����
				if (node->right)
					st.push(node->right);		// �����ҽ��
				st.push(node);
				st.push(NULL);					// �н����ʹ���û��������ս��
				if (node->left)
					st.push(node->left);		// ��������
			}
			// �����ս�㣬�����㣨���ʹ����ǻ�û����
			else
			{
				st.pop();
				node = st.top();
				st.pop();
				ans.push_back(node->val);		// ���뵽�����
			}
		}
		return ans;
	}
};