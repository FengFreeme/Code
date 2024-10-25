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

class Solution {
public:
	/*
	// �ݹ� ������� ������
	bool hasPathSum(TreeNode* root, int targetSum) 
	{
		vector<int> path;
		if (root == NULL)
			return false;
		path.push_back(root->val);
		return preorder(root, path, targetSum);
	}
	// 1. ȷ�������ͷ��ز���
	bool preorder(TreeNode* root, vector<int>& path, int targetSum)
	{
		// 2. ȷ����ֹ����
		if (root->left == NULL && root->right == NULL)
		{
			int size = path.size();
			int sum = 0;
			for (int i = 0; i < size; i++)
			{
				sum += path[i];
			}
			
			if (sum == targetSum)
				return true;
			else
				return false;
		}
		bool ans1 = false;
		bool ans2 = false;
		// 3. ���εݹ鴦��
		if (root->left != NULL)
		{
			path.push_back(root->left->val);
			ans1 = preorder(root->left, path, targetSum);
			path.pop_back();		// ����
		}
		if (root->right != NULL)
		{
			path.push_back(root->right->val);
			ans2 = preorder(root->right, path, targetSum);
			path.pop_back();		// ����
		}
		return ans1 || ans2;
	}
	*/
	// ���� ������� ������
	bool hasPathSum(TreeNode* root, int targetSum)
	{
		if (root == NULL)
			return false;
		stack<TreeNode*> st;
		stack<vector<int>> pathSt;
		vector<int> path;
		path.push_back(root->val);
		pathSt.push(path);
		st.push(root);
		int sum = 0;
		while (!st.empty())
		{
			TreeNode* node = st.top();		// ��
			st.pop();
			path = pathSt.top();
			pathSt.pop();
			if (node->left == NULL && node->right == NULL)
			{
				sum = 0;
				for (int i = 0; i < path.size(); i++)
				{
					sum += path[i];
				}
				if (sum == targetSum)
					return true;
			}
			if(node->right != NULL)
			{
				st.push(node->right);			// ��
				vector<int> temp = path;
				temp.push_back(node->right->val);
				pathSt.push(temp);
			}
			if(node->left != NULL)
			{
				st.push(node->left);			// ��
				vector<int> temp = path;
				temp.push_back(node->left->val);
				pathSt.push(temp);
			}
		}
		return false;
	}
	bool hasPathSum(TreeNode* root, int targetSum)
	{
		if (root == NULL)
			return false;
		return traversal(root, targetSum - root->val);
	}
private:
	bool traversal(TreeNode* cur, int count)
	{
		if (cur->left == NULL && cur->right == NULL && count == 0)
			return true;
		//2. ��ֹ���� ����Ҷ�ӽڵ㷵��
		if (cur->left == NULL && cur->right == NULL)
			return false;

		if (cur->left != NULL)		// ��
		{
			count -= cur->left->val;	// �ݹ飬����ڵ�
			if (traversal(cur->left, count))
				return true;
			count += cur->left->val;	// ���ݣ�����������
		}
		if (cur->right)				// ��
		{
			count -= cur->right->val;	// �ݹ飬����ڵ�
			if (traversal(cur->right, count))
				return true;
			count += cur->right->val;	// ���ݣ�����������
		}
		return false;
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
	S.hasPathSum(root, 4);

	return 0;
}