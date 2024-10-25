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
	vector<int> inorderTraversal(TreeNode* root) 
	{
		vector<int> ans;
		traversal(root, ans);

		return ans;
	}

	void traversal(TreeNode* root, vector<int>& ans)
	{
		if (root == NULL)
			return;
		traversal(root->left, ans);
		ans.push_back(root->val);
		traversal(root->right, ans);
	}
	// 中序遍历 非递归 注意处理顺序和访问顺序不一致
	vector<int> inorderTraversal(TreeNode* root)
	{
		stack<TreeNode*> st;
		vector<int> ans;
		if (root == NULL)
			return ans;
		// st.push(root);
		TreeNode* cur = root;
		while (cur != NULL || !st.empty())
		{
			if (cur != NULL)
			{
				st.push(cur);
				cur = cur->left;			// 左
			}
			else
			{
				cur = st.top();
				ans.push_back(cur->val);	// 中
				st.pop();
				cur = cur->right;			// 右
			}
		}
		return ans;
	}
	// 中序遍历 统一迭代风格 另一种标记法
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> ans;
		stack<TreeNode*> st;
		if (root != NULL)
			st.push(root);
		while (!st.empty())
		{
			TreeNode* node = st.top();
			if (node != NULL)
			{
				st.pop();		// 将该节点弹出，避免重复操作
				if (node->right)
					st.push(node->right);		// 加入右结点
				st.push(node);
				st.push(NULL);					// 中结点访问过还没处理，加入空结点
				if (node->left)
					st.push(node->left);		// 加入左结点
			}
			// 遇到空结点，处理结点（访问过但是还没处理）
			else
			{
				st.pop();
				node = st.top();
				st.pop();
				ans.push_back(node->val);		// 加入到结果集
			}
		}
		return ans;
	}
};