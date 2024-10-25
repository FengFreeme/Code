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
	vector<double> averageOfLevels(TreeNode* root) 
	{
		vector<double> ans;
		deque<TreeNode*> que;
		if (root != NULL)
			que.push_back(root);
		while (!que.empty())
		{
			int size = que.size();
			double avg;
			double sum = 0;
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = que.front();
				sum += node->val;
				que.pop_front();
				if (node->left != NULL)
					que.push_back(node->left);
				if (node->right != NULL)
					que.push_back(node->right);
			}
			avg = sum / size;
			ans.push_back(avg);
		}
		return ans;
	}
};