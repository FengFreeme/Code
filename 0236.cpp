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
    // 后序遍历，实现回溯判断 自底向上遍历
    // 1. 确定参数和返回参数
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        // 2. 终止条件
        // 回溯的过程需要递归函数的返回值做判断
        if (root == p || root == q || root == NULL)
            return root;
        // 单次递归处理
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != NULL && right != NULL)
            return root;
        else if (left == NULL && right != NULL)
            return right;
        else if (left != NULL && right == NULL)
            return left;
        else 
            return NULL;
    }
};

int main()
{
    TreeNode* root = new TreeNode(3);
    TreeNode* node = root;
    node->left = new TreeNode(5);
    node->right = new TreeNode(1);
    // TreeNode* left = node->left;
    // TreeNode* right = node->right;
    node->left->left = new TreeNode(6);
    node->left->right = new TreeNode(2);
    node->right->left = new TreeNode(0);
    node->right->right = new TreeNode(8);
    node->left->right->left = new TreeNode(7);
    node->left->right->right = new TreeNode(4);
    TreeNode* left = node->left->right->left;
    TreeNode* right = node->left->right->right;
    Solution S;
    S.lowestCommonAncestor(root, left, right);

    return 0;
}