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
	// 递归遍历 先序 叶子节点
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
	// 1. 确定参数和返回参数
	void preorder(TreeNode* root, vector<int> &ans, vector<string>&string_ans)
	{
		/// 2. 确定终止条件

		ans.push_back(root->val);

		// 3. 单次递归处理
		// 是叶子结点
		if (root->left == NULL && root->right == NULL)		// 中
		{
			string path = "";
			for (int i = 0; i < ans.size(); i++)
			{
				if (i == 0)
				{
					// to_string 将数字常量转换为字符串
					path = path + to_string(ans[i]);
					continue;
				}
				path = path + "->";
				path = path + to_string(ans[i]);
			}
			string_ans.push_back(path);
		}
		
		if (root->left != NULL)			// 左
		{
			preorder(root->left, ans, string_ans);
			ans.pop_back();
		}
		if (root->right != NULL)		// 右
		{
			preorder(root->right, ans, string_ans);
			ans.pop_back();
		}
		return;
	}
	*/
	// 非递归 统一迭代法实现先序遍历 中 左 右 不能回溯 好像没法用统一迭代法 用常规方法
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
			st.pop();						// 中
			string path = pathSt.top();
			pathSt.pop();					// 取出路径
			if (node->left == NULL && node->right == NULL)
				string_ans.push_back(path);
			if (node->right != NULL)
			{
				st.push(node->right);		// 右
				pathSt.push(path + "->" + to_string(node->right->val));
			}
			if (node->left != NULL)			// 左
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