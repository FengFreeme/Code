#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        traversal(root, ans);

        return ans;
    }
    void traversal(TreeNode* root, vector<int>& ans)
    {
        if (root == NULL)
            return;
        ans.push_back(root->val);
        traversal(root->left, ans);
        traversal(root->right, ans);
    }
    // 前序遍历 非递归
    vector<int> preorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> st;
        vector<int> ans;
        if (root == NULL)
            return ans;
        st.push(root);
        while (!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            if (node->right != NULL)
                st.push(node->right);
            if (node->left != NULL)
                st.push(node->left);
            ans.push_back(node->val);
        }
        return ans;
    }
    // 先序遍历 非递归 统一风格
    vector<int> preorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> st;
        vector<int> ans;
        if (root != NULL)
            st.push(root);
        while (!st.empty())
        {
            TreeNode* node = st.top();
            // 此时还未访问过
            if (node != NULL)
            {
                st.pop();
                if (node->right != NULL)
                    st.push(node->right);
                if (node->left != NULL)
                    st.push(node->left);
                st.push(node);
                st.push(NULL);
            }
            // 已经访问过，还未处理
            else
            {
                st.pop();
                node = st.top();
                ans.push_back(node->val);
                st.pop();
            }
        }
        return ans;
    }
};