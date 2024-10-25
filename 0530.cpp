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
	int getMinimumDifference(TreeNode* root) 
	{
		Inorder(root);
		
		return min_distance;
	}

	// ������� �ݹ�
	TreeNode* pre = NULL;
	int min_distance = INT_MAX;
	void Inorder(TreeNode* root)
	{
		// 2. ȷ����ֹ����
		if (root == NULL)
			return;
		// 3. ���εݹ鴦��
		Inorder(root->left);
		if (pre != NULL)
		{
			int distance = root->val - pre->val;
			min_distance = distance < min_distance ? distance : min_distance;
		}
		pre = root;
		Inorder(root->right);
	}
	*/
	int getMinimumDifference(TreeNode* root)
	{
		stack<TreeNode*> st;
		TreeNode* cur = root;
		TreeNode* pre = NULL;
		int min_distance = INT_MAX;
		while (cur != NULL || !st.empty())
		{
			if (cur != NULL)
			{
				st.push(cur);		
				cur = cur->left;			// ��
			}
			else 
			{
				cur = st.top();				// ��
				st.pop();
				if (pre != NULL)
				{
					int distance = cur->val - pre->val;
					min_distance = distance < min_distance ? distance : min_distance;
				}
				pre = cur;
				cur = cur->right;			// ��
			}
		}
		return min_distance;
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
	S.getMinimumDifference(root);

	return 0;
}