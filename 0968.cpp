#include <iostream>
#include <vector>

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
	int ans = 0;
	int minCameraCover(TreeNode* root) 
	{
		// ���4
		// root�޸���
		if (postorder(root) == 0)
			ans++;
		return ans;
	}
	// 1. ȷ�������ͷ��ز���
	int postorder(TreeNode* root)
	{
		// 2. ȷ����ֹ����
		// �ս�� �ý���и���
		if (root == NULL)
			return 2;
		// 3. ���εݹ鴦��
		int left = postorder(root->left);
		int right = postorder(root->right);

		// ���1
		// ���ҽ�㶼�и���
		if (left == 2 && right == 2)
			return 0;

		// ���2
		// left == 0 && right == 0 ���ҽڵ��޸���
		// left == 1 && right == 0 ��ڵ�������ͷ���ҽڵ��޸���
		// left == 0 && right == 1 ��ڵ��޸��ǣ��ҽڵ�������ͷ
		// left == 0 && right == 2 ��ڵ��޸��ǣ��ҽڵ��и���
		// left == 2 && right == 0 ��ڵ��и��ǣ��ҽڵ��޸���
		if (left == 0 || right == 0)
		{
			ans++;
			return 1;
		}
		// ���3
		// left == 1 && right == 2 ��ڵ�������ͷ���ҽڵ��޸���
		// left == 2 && right == 1 ��ڵ��и��ǣ��ҽڵ�������ͷ
		// left == 1 && right == 1 ���ҽڵ㶼������ͷ
		if (left == 1 || right == 1)
		{
			return 2;
		}
		// �߼������ߵ�����
		return -1;
	}
};