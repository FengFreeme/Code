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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
	{
		return Build(nums);
	}
	TreeNode* Build(vector<int>& nums)
	{
		if (nums.size() == 0)
			return NULL;
		int max_value = nums[0];
		int index = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if (max_value < nums[i])
			{
				max_value = nums[i];
				index = i;
			}
		}
		TreeNode* node = new TreeNode(max_value);
		if (nums.size() == 1)
			return node;
		// 分割数组 左闭右开
		vector<int> leftnums(nums.begin(), nums.begin() + index);
		vector<int> rightnums(nums.begin() + index + 1, nums.end());

		node->left = Build(leftnums);
		node->right = Build(rightnums);

		return node;
	}
};

int main()
{
	vector<int> nums = { 3, 2, 1, 6, 0, 5 };

	Solution S;
	S.constructMaximumBinaryTree(nums);

	return 0;
}