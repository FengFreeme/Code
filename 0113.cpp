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
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
	{
		vector<vector<int>> ans;
		if (root == NULL)
			return ans;
		vector<int> path;
		path.push_back(root->val);
		preorder(root, ans, path, targetSum);

		return ans;
	}

	void preorder(TreeNode* root, vector<vector<int>>& ans, vector<int>& path, int targetSum)
	{
		if (root->left == NULL && root->right == NULL)
		{
			int size = path.size();
			int sum = 0;
			for (int i = 0; i < size; i++)
			{
				sum += path[i];
			}
			if (sum == targetSum)
				ans.push_back(path);
		}
		if (root->left != NULL)
		{
			path.push_back(root->left->val);		// µÝ¹é
			preorder(root->left, ans, path, targetSum);
			path.pop_back();						// »ØËÝ
		}
		if (root->right != NULL)
		{
			path.push_back(root->right->val);		// µÝ¹é
			preorder(root->right, ans, path, targetSum);
			path.pop_back();						// »ØËÝ
		}
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* node = root;
	node->left = new TreeNode(2);
	node->right = new TreeNode(3);
	// node->left->left = new TreeNode(4);
	node->left->right = new TreeNode(5);
	node->right->left = new TreeNode(4);
	// node->right->right = new TreeNode(7);

	Solution S;
	S.pathSum(root, 8);

	return 0;
}