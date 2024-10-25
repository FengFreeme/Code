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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
	{
		if (inorder.size() == 0 || preorder.size() == 0)
			return NULL;
		return traversal(preorder, inorder);
	}

	TreeNode* traversal(vector<int>& preorder, vector<int>& inorder)
	{
		// 第一步
		if (preorder.size() == 0)
			return 0;

		// 第二步
		int Value = preorder[0];
		TreeNode* root = new TreeNode(Value);
		// 叶子结点
		if (preorder.size() == 1)
			return root;

		// 第三步 确定分割区间
		int delimiterIndex;
		for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++)
			if (inorder[delimiterIndex] == Value)
				break;
		// 第四步 左闭右开 [0, delimiterIndex)
		vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);		// 初始化左闭右开区间
		// [delimiterIndex + 1, inorder.end()]
		vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

		vector<int> new_preorder(preorder.begin() + 1, preorder.end());
		vector<int> leftPreorder(new_preorder.begin(), new_preorder.begin() + leftInorder.size());
		vector<int> rightPreorder(new_preorder.begin() + leftInorder.size(), new_preorder.end());

		root->left = traversal(leftPreorder, leftInorder);
		root->right = traversal(rightPreorder, rightInorder);

		return root;
	}
};

int main()
{
	vector<int> preorder = { 3, 9, 20, 15, 7 }, inorder = { 9, 3, 15, 20, 7 };

	Solution S;
	S.buildTree(preorder, inorder);

	return 0;
}