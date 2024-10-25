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
	// 递归 先序遍历 中左右
	bool hasPathSum(TreeNode* root, int targetSum) 
	{
		vector<int> path;
		if (root == NULL)
			return false;
		path.push_back(root->val);
		return preorder(root, path, targetSum);
	}
	// 1. 确定参数和返回参数
	bool preorder(TreeNode* root, vector<int>& path, int targetSum)
	{
		// 2. 确定终止条件
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
		// 3. 单次递归处理
		if (root->left != NULL)
		{
			path.push_back(root->left->val);
			ans1 = preorder(root->left, path, targetSum);
			path.pop_back();		// 回溯
		}
		if (root->right != NULL)
		{
			path.push_back(root->right->val);
			ans2 = preorder(root->right, path, targetSum);
			path.pop_back();		// 回溯
		}
		return ans1 || ans2;
	}
	*/
	// 迭代 先序遍历 中左右
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
			TreeNode* node = st.top();		// 中
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
				st.push(node->right);			// 右
				vector<int> temp = path;
				temp.push_back(node->right->val);
				pathSt.push(temp);
			}
			if(node->left != NULL)
			{
				st.push(node->left);			// 左
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
		//2. 终止条件 遇到叶子节点返回
		if (cur->left == NULL && cur->right == NULL)
			return false;

		if (cur->left != NULL)		// 左
		{
			count -= cur->left->val;	// 递归，处理节点
			if (traversal(cur->left, count))
				return true;
			count += cur->left->val;	// 回溯，撤销处理结果
		}
		if (cur->right)				// 右
		{
			count -= cur->right->val;	// 递归，处理节点
			if (traversal(cur->right, count))
				return true;
			count += cur->right->val;	// 回溯，撤销处理结果
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