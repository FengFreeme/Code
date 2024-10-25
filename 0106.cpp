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
		// ��һ��
		if (postorder.size() == 0)
			return NULL;
		// �ڶ��� ��������������һ��Ԫ�� ��ǰ�м���
		int rootValue = postorder[postorder.size() - 1];
		TreeNode* root = new TreeNode(rootValue);

		// Ҷ�ӽ��
		if (postorder.size() == 1)
			return root;

		// ������ ���и��
		int delimiterIndex;
		for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++)
			if (inorder[delimiterIndex] == rootValue)
				break;

		// ���Ĳ� �и��������� ����ҿ�
		// [0, delimiterIndex)
		vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
		// [delimiterIndex + 1, end)
		vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

		// ������������ĩβԪ�أ��м�ڵ㣩
		postorder.resize(postorder.size() - 1);

		// ����ҿ�
		// [0, leftInorder.size()]
		vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
		// [leftInorder.size(), end)
		vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());
		
		// ������
		root->left = traversal(leftInorder, leftPostorder);
		root->right = traversal(rightInorder, rightPostorder);

		return root;
	}
};