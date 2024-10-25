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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		if (inorder.size() == 0 || postorder.size() == 0)
			return NULL;
		return traversal(inorder, postorder);
	}
	TreeNode* traversal(vector<int>& inorder, vector<int>& postorder)
	{
		// 第一步
		if (postorder.size() == 0)
			return NULL;
		// 第二步 后序遍历数组最后一个元素 当前中间结点
		int rootValue = postorder[postorder.size() - 1];
		TreeNode* root = new TreeNode(rootValue);

		// 叶子结点
		if (postorder.size() == 1)
			return root;

		// 第三步 找切割点
		int delimiterIndex;
		for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++)
			if (inorder[delimiterIndex] == rootValue)
				break;

		// 第四步 切割中序数组 左闭右开
		// [0, delimiterIndex)
		vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
		// [delimiterIndex + 1, end)
		vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

		// 后序数组舍弃末尾元素（中间节点）
		postorder.resize(postorder.size() - 1);

		// 左闭右开
		// [0, leftInorder.size()]
		vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
		// [leftInorder.size(), end)
		vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());
		
		// 第六步
		root->left = traversal(leftInorder, leftPostorder);
		root->right = traversal(rightInorder, rightPostorder);

		return root;
	}
};