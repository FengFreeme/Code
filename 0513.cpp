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
	// ȫ�ֱ���
	int maxDepth = INT_MIN;
	int ans;
	int findBottomLeftValue(TreeNode* root) 
	{
		traversal(root, 1);

		return ans;
	}
	// ʹ�����������֤������
	// ��֤�������������Ȼ���¼�������Ҷ�ӽڵ㣬��ʱ�����������һ������ߵ�ֵ
	// 1. ȷ�������ͷ��ز���
	void traversal(TreeNode* root, int depth)
	{
		// 2. ��ֹ���� ������
		if (root->left == NULL && root->right == NULL)
		{
			// ֻ������ȸ���ʱ�ŻὫ�������Ϊ����ߵ�ֵ
			if(depth > maxDepth)
			{
				maxDepth = depth;
				ans = root->val;
			}
			return;
		}
		// 3. ���εݹ�
										// ��
		if (root->left != NULL)			// ��
		{
			depth++;
			traversal(root->left, depth);
			depth--;
		}
		if (root->right != NULL)		// ��
		{
			depth++;
			traversal(root->right, depth);
			depth--;
		}
		
		return;
	}
	// �������
	int findBottomLeftValue(TreeNode* root)
	{
		deque<TreeNode*> que;
		que.push_back(root);
		int ans;
		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = que.front();
				if (i == 0)
					ans = node->val;
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
	node->left = new TreeNode(2);
	node->right = new TreeNode(3);
	node->left->left = new TreeNode(4);
	node->left->right = new TreeNode(5);
	// node->right->left = new TreeNode(4);
	// node->right->right = new TreeNode(7);

	Solution S;
	S.findBottomLeftValue(root);

	return 0;
}