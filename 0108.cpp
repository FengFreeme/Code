#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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
	// 1. ȷ�������ͷ��ز���
	TreeNode* sortedArrayToBST(vector<int>& nums) 
	{
		// 2. ȷ����ֹ����
		if (nums.size() == 0)
			return NULL;
		int size = nums.size();
		int index = size / 2;
		TreeNode* node = new TreeNode(nums[index]);
		if (nums.size() == 1)
		{
			return node;
		}

		// 3. ���εݹ鴦��
		vector<int> leftnums(nums.begin(), nums.begin() + index);		// ����ҿ�
		vector<int> rightnums(nums.begin() + index + 1, nums.end());	// ����ҿ�

		node->left = sortedArrayToBST(leftnums);
		node->right = sortedArrayToBST(rightnums);

		return node;
	}
	TreeNode* traversal(vector<int>& nums, int left, int right)
	{
		if (left > right)
			return NULL;
		int mid = left + ((right - left) / 2);
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = traversal(nums, left, mid - 1);
		root->right = traversal(nums, mid + 1, right);

		return root;
	}
	// ��һ�ֵݹ�
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		TreeNode* root = traversal(nums, 0, nums.size() - 1);
		return root;
	}
	*/
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		if (nums.size() == 0)
			return NULL;

		TreeNode* root = new TreeNode(0);		// ��ʼ���ڵ�
		queue<TreeNode*> nodeQue;				// �����ڵ����
		queue<int> leftQue;						// �����������±�
		queue<int> rightQue;

		nodeQue.push(root);
		leftQue.push(0);
		rightQue.push(nums.size() - 1);

		while (!nodeQue.empty())
		{
			TreeNode* curNode = nodeQue.front();
			nodeQue.pop();
			int left = leftQue.front();
			leftQue.pop();
			int right = rightQue.front();
			rightQue.pop();
			int mid = left + ((right - left) / 2);

			curNode->val = nums[mid];

			// ����������
			if (left <= mid - 1)
			{
				curNode->left = new TreeNode(0);
				nodeQue.push(curNode->left);
				leftQue.push(left);
				rightQue.push(mid - 1);
			}
			// ����������
			if (right >= mid + 1)
			{
				curNode->right = new TreeNode(0);
				nodeQue.push(curNode->right);
				leftQue.push(mid + 1);
				rightQue.push(right);
			}
		}
		return root;
	}
};

int main()
{
	vector<int> nums = { -10,-3,0,5,9 };

	Solution S;
	S.sortedArrayToBST(nums);

	return 0;
}