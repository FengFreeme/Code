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
	// ������� ʵ��
	int countNodes(TreeNode* root) 
	{
		int depth = 0;
		deque<TreeNode*> que;
		if (root == NULL)
			return 0;
		que.push_back(root);
		// ���һ�������
		int LastNum;
		while (!que.empty())
		{
			depth++;
			int size = que.size();
			LastNum = size;
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
		int ans = pow(2, depth - 1) - 1 + LastNum;

		return ans;
	}
	*/
	int ans;
	// ������� �ݹ� ���������Լ���Ӧ�������
	int countNodes(TreeNode* root)
	{
		// ��¼ÿһ��������
		vector<int> record;
		ans = 0;
		if (root == NULL)
			return 0;
		getDepth(root, 1, record);

		int result = pow(2, ans - 1) - 1 + record[ans - 1];

		return result;
	}
	// 1. �����ͷ��ز���
	void getDepth(TreeNode* cur, int depth, vector<int>& record)
	{
		// 3. ���εݹ鴦��
		if (record.size() < depth)
			record.push_back(int(0));
		record[depth - 1]++;
		// depth �ǵ�ǰ�������
		ans = ans > depth ? ans : depth;			// ��
		// 2. ��ֹ����
		if (cur->left == NULL && cur->right == NULL) 
			return;
		if (cur->left != NULL)
		{
			depth++;
			getDepth(cur->left, depth, record);		// ��
			depth--;
		}
		if (cur->right != NULL)
		{
			depth++;
			getDepth(cur->right, depth, record);	// ��
			depth--;
		}
		return;
	}
	// ���ö���������
	// �ֱ�ݹ����ӣ����Һ���
	// �ݹ鵽ĳһ���һ���������ӻ����Һ���Ϊ��������
	// �������
	int countNodes(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		int leftDepth = 0;
		int rightDepth = 0;
		while (left)
		{
			left = left->left;
			leftDepth++;
		}
		while (right)
		{
			right = right->right;
			rightDepth++;
		}
		if (leftDepth == rightDepth)
		{
			return pow(2, leftDepth + 1) - 1;
		}
		return countNodes(root->left) + countNodes(root->right) + 1;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	// TreeNode* node = root;
	// node->left = new TreeNode(2);
	// node->right = new TreeNode(3);
	// node->left->left = new TreeNode(4);
	// node->left->right = new TreeNode(5);
	// node->right->right = new TreeNode(7);

	Solution S;
	S.countNodes(root);

	return 0;
}