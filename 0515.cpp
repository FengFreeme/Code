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
	vector<int> largestValues(TreeNode* root) 
	{
		vector<int> ans;
		deque<TreeNode*> que;
		if (root != NULL)
			que.push_back(root);
		while (!que.empty())
		{
			int size = que.size();
			int max_value = INT_MIN;
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = que.front();
				if (max_value < node->val)
					max_value = node->val;
				que.pop_front();
				if (node->left != NULL)
					que.push_back(node->left);
				if (node->right != NULL)
					que.push_back(node->right);
			}
			ans.push_back(max_value);
		}
		return ans;
	}
};