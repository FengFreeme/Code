#include <iostream>
#include <vector>
#include <stack>
#include <string>

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
	// �ݹ���� ���� Ҷ�ӽڵ�
	vector<string> binaryTreePaths(TreeNode* root) 
	{
		vector<int> ans;
		vector<string> string_ans;
		if (root == NULL)
			return string_ans;
		else
		{
			preorder(root, ans, string_ans);

			return string_ans;
		}
	}
	// 1. ȷ�������ͷ��ز���
	void preorder(TreeNode* root, vector<int> &ans, vector<string>&string_ans)
	{
		/// 2. ȷ����ֹ����

		ans.push_back(root->val);

		// 3. ���εݹ鴦��
		// ��Ҷ�ӽ��
		if (root->left == NULL && root->right == NULL)		// ��
		{
			string path = "";
			for (int i = 0; i < ans.size(); i++)
			{
				if (i == 0)
				{
					// to_string �����ֳ���ת��Ϊ�ַ���
					path = path + to_string(ans[i]);
					continue;
				}
				path = path + "->";
				path = path + to_string(ans[i]);
			}
			string_ans.push_back(path);
		}
		
		if (root->left != NULL)			// ��
		{
			preorder(root->left, ans, string_ans);
			ans.pop_back();
		}
		if (root->right != NULL)		// ��
		{
			preorder(root->right, ans, string_ans);
			ans.pop_back();
		}
		return;
	}
	*/
	// �ǵݹ� ͳһ������ʵ��������� �� �� �� ���ܻ��� ����û����ͳһ������ �ó��淽��
	vector<string> binaryTreePaths(TreeNode* root)
	{
		vector<string> string_ans;
		if (root == NULL)
			return string_ans;
		stack<TreeNode*> st;
		stack<string> pathSt;
		st.push(root);
		pathSt.push(to_string(root->val));
		while (!st.empty())
		{
			TreeNode* node = st.top();
			st.pop();						// ��
			string path = pathSt.top();
			pathSt.pop();					// ȡ��·��
			if (node->left == NULL && node->right == NULL)
				string_ans.push_back(path);
			if (node->right != NULL)
			{
				st.push(node->right);		// ��
				pathSt.push(path + "->" + to_string(node->right->val));
			}
			if (node->left != NULL)			// ��
			{
				st.push(node->left);
				pathSt.push(path + "->" + to_string(node->left->val));
			}
		}
		return string_ans;
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
	S.binaryTreePaths(root);

	return 0;
}