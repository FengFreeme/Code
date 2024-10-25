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
		// 情况4
		// root无覆盖
		if (postorder(root) == 0)
			ans++;
		return ans;
	}
	// 1. 确定参数和返回参数
	int postorder(TreeNode* root)
	{
		// 2. 确定终止条件
		// 空结点 该结点有覆盖
		if (root == NULL)
			return 2;
		// 3. 单次递归处理
		int left = postorder(root->left);
		int right = postorder(root->right);

		// 情况1
		// 左右结点都有覆盖
		if (left == 2 && right == 2)
			return 0;

		// 情况2
		// left == 0 && right == 0 左右节点无覆盖
		// left == 1 && right == 0 左节点有摄像头，右节点无覆盖
		// left == 0 && right == 1 左节点无覆盖，右节点有摄像头
		// left == 0 && right == 2 左节点无覆盖，右节点有覆盖
		// left == 2 && right == 0 左节点有覆盖，右节点无覆盖
		if (left == 0 || right == 0)
		{
			ans++;
			return 1;
		}
		// 情况3
		// left == 1 && right == 2 左节点有摄像头，右节点无覆盖
		// left == 2 && right == 1 左节点有覆盖，右节点有摄像头
		// left == 1 && right == 1 左右节点都有摄像头
		if (left == 1 || right == 1)
		{
			return 2;
		}
		// 逻辑不会走到这里
		return -1;
	}
};