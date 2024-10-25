#include <iostream>
#include <vector>
#include <deque>

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
	vector<int> rightSideView(TreeNode* root) 
	{
		vector<int> ans;
		deque<TreeNode*> que;
		if (root != NULL)
			que.push_back(root);
		else
			return ans;
		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = que.front();
				if (i == size - 1)
					ans.push_back(node->val);
				que.pop_front();
				if (node->left != NULL)
					que.push_back(node->left);
				if (node->right != NULL)
					que.push_back(node->right);
			}
		}
		return ans;
	}
};