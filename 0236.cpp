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
    // ���������ʵ�ֻ����ж� �Ե����ϱ���
    // 1. ȷ�������ͷ��ز���
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        // 2. ��ֹ����
        // ���ݵĹ�����Ҫ�ݹ麯���ķ���ֵ���ж�
        if (root == p || root == q || root == NULL)
            return root;
        // ���εݹ鴦��
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