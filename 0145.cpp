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
// 后序遍历
class Solution 
{
public:
	struct Tree
	{
		TreeNode* root;
		int tag = -1;
		
	};
	//vector<int> postorderTraversal(TreeNode* root) 
	//{
	//	vector<int> ans;
	//	traversal(root, ans);
	//	return ans;
	//}

	//void traversal(TreeNode* root, vector<int>& ans)
	//{
	//	if (root == NULL)
	//		return;
	//	traversal(root->left, ans);
	//	traversal(root->right, ans);
	//	ans.push_back(root->val);
	//}
	//// 后序遍历 非递归
	//vector<int> postorderTraversal(TreeNode* root)
	//{
	//	stack<TreeNode*> st;
	//	vector<int> ans;
	//	if (root == NULL)
	//		return ans;
	//	st.push(root);
	//	while (!st.empty())
	//	{
	//		TreeNode* node = st.top();
	//		ans.push_back(node->val);
	//		st.pop();
	//		if (node->left != NULL)
	//			st.push(node->left);
	//		if (node->right != NULL)
	//			st.push(node->right);
	//	}
	//	reverse(ans.begin(), ans.end());
	//	return ans;
	//}
	// 后序遍历 非递归 标志法 先遍历到最底层的左子树再开始处理
	vector<int> postorderTraversal(TreeNode* root)
	{
		stack<Tree> st;
		vector<int> ans;
		TreeNode* cur = root;
		while (cur != NULL || !st.empty())
		{
			if (cur != NULL)
			{
				Tree t1;
				t1.root = cur;

				t1.tag = 0;			// 表示左子树被访问
				cur = cur->left;	// 遍历到最底层的左子树结点
				st.push(t1);
			}
			else
			{
				Tree t2 = st.top();
				// 右子树已经访问过
				if (t2.tag == 1)
				{
					ans.push_back(t2.root->val);
					st.pop();
				}
				// 右子树还未访问过，先访问右子树
				else if(t2.tag == 0)
				{
					cur = t2.root->right;
					st.top().tag = 1;
				}
			}
		}
		return ans;
	}
	// 后序遍历 统一非递归风格
	vector<int> postorderTraversal(TreeNode* root)
	{
		stack<TreeNode*> st;
		vector<int> ans;
		if (root != NULL)
			st.push(root);
		else
			return ans;
		while (!st.empty())
		{
			TreeNode* node = st.top();
			// 未访问
			if (node != NULL)
			{
				st.pop();
				st.push(node);
				st.push(NULL);
				if (node->right != NULL)
					st.push(node->right);
				if (node->left != NULL)
					st.push(node->left);
			}
			// 访问过未处理
			else
			{
				st.pop();			// 先弹出空结点
				// 开始处理
				node = st.top();
				ans.push_back(node->val);
				st.pop();
			}
		}
		return ans;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* node = root;
	node->right = new TreeNode(2);
	node = node->right;
	node->left = new TreeNode(3);

	Solution S;
	S.postorderTraversal(root);

	return 0;
}