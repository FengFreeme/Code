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
	/*
	int maxDepth(TreeNode* root) 
	{
		int depth = 0;
		depth = order(root, depth);

		return depth;
	}
	// 1. ȷ�������ͷ���ֵ
	int order(TreeNode* cur, int depth)
	{
		// 2. ��ֹ����
		if (cur == NULL)
			return depth;
		else
			depth++;
		// 3. ȷ������ݹ���߼�
		int temp1 = order(cur->left, depth);
		int temp2 = order(cur->right, depth);
		depth = depth < temp1 ? temp1 : depth;
		depth = depth < temp2 ? temp2 : depth;
	}
	
	int maxDepth(TreeNode* root)
	{
		return getDepth(root);
	}
	// ������� �ݹ�
	int getDepth(TreeNode* node)
	{
		if (node == NULL)
			return 0;
		int leftDepth = getDepth(node->left);
		int rightDepth = getDepth(node->right);
		// ������������������ȣ����������������
		// ���ȡ�������������ֵ ��+1 ����1����Ϊ���ϵ�ǰ�м�ڵ㣩����Ŀǰ�ڵ�Ϊ���ڵ��������ȡ�
		int depth = 1 + max(leftDepth, rightDepth);

		return depth;
	}
	
	// ���м����1��������ҽ��
	// �������
	int ans;
	void getDepth(TreeNode* node, int depth)
	{
		ans = depth > ans ? depth : ans;		// ��
		if (node->left == NULL && node->right == NULL)
			return;
		if (node->left != NULL)					// ��
		{
			depth++;							// ���+1
			getDepth(node->left, depth);
			depth--;							// ���� ���-1
		}
		if (node->right != NULL)				// ��
		{
			depth++;
			getDepth(node->right, depth);
			depth--;
		}
		return;
	}
	int maxDepth(TreeNode* root)
	{
		ans = 0;
		if (root == NULL)
			return ans;
		getDepth(root, 1);

		return ans;
	}
	*/
	// ������� ����
	int maxDepth(TreeNode* root)
	{
		int ans = 0;
		deque<TreeNode*> que;
		if (root != NULL)
			que.push_back(root);
		while (!que.empty())
		{
			ans++;
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = que.front();
				que.pop_front();
				if (node->left != NULL)
					que.push_back(node->left);
				if (node->right != NULL)
					que.push_back(node->right);
			}
		}
		return ans;
	}
};


int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* node = root;
	// node->left = new TreeNode(9);
	node->right = new TreeNode(2);
	node->right->left = new TreeNode(3);
	// node->right->right = new TreeNode(7);

	Solution S;
	S.maxDepth(root);

	return 0;
}
