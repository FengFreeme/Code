#include <iostream>
#include <vector>

using namespace std;

struct TreeNode 
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
	int rob(TreeNode* root) 
	{

	}
};

int main()
{
	vector<int> root_1 = { 3, 2, 3, -1, 3, -1, 1 };
	TreeNode* root = new TreeNode(root_1[0]);
}