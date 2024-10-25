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
	TreeNode* pre = NULL;
	int max_count = INT_MIN;
	int count = 0;
	vector<int> ans;
	vector<int> findMode(TreeNode* root) 
	{
		if (root->left == NULL && root->right == NULL)
		{
			ans.push_back(root->val);

			return ans;
		}
		Inorder(root);

		return ans;
	}
	// 1. ȷ�������ͷ��ز���
	void Inorder(TreeNode* root)
	{
		// 2. ȷ����ֹ����
		if (root == NULL)
		{
			return;
		}
		// 3. ���εݹ鴦��
		Inorder(root->left);
		if (pre == NULL)									// ��һ�����
			count = 1;
		else if (pre->val == root->val)
		{
			count++;
		}
		else if (pre->val != root->val)
		{
			count = 1;
		}
		pre = root;

		if (max_count < count)
		{
			max_count = count;
			ans.clear();
			ans.push_back(pre->val);
		}
		else if (max_count == count)
		{
			ans.push_back(pre->val);
		}
		Inorder(root->right);

		return;
	}
	*/
	// ��������� �������
	vector<int> findMode(TreeNode* root)
	{
		int max_count = INT_MIN;
		int count = 0;
		vector<int> ans;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		TreeNode* pre = NULL;
		while (cur != NULL || !st.empty())
		{
			if (cur != NULL)
			{
				st.push(cur);
				cur = cur->left;		// ��
			}
			else
			{
				cur = st.top();
				st.pop();
				if (pre == NULL)
					count = 1;
				else if (pre->val == cur->val)
					count++;
				else if (pre->val != cur->val)
					count = 1;

				pre = cur;

				if (max_count < count)
				{
					max_count = count;
					ans.clear();
					ans.push_back(cur->val);
				}
				else if (max_count == count)
				{
					ans.push_back(cur->val);
				}
				cur = cur->right;
			}
		}
		return ans;
	}
};

int main()
{
	TreeNode* root = new TreeNode(2);
	TreeNode* node = root;
	node->left = new TreeNode(1);;
	node = node->left;
	node->right = new TreeNode(2);
	node = node->right;
	node->left = new TreeNode(1);;
	node = node->left;
	node->right = new TreeNode(2);
	node = node->right;
	
	// node->left = new TreeNode(2);
	//node->right = new TreeNode(2);
	// node->left->left = new TreeNode(1);
	// node->left->right = new TreeNode(3);
	// node->right->left = new TreeNode(2);
	// node->right->right = new TreeNode(7);

	Solution S;
	S.findMode(root);

	return 0;
}