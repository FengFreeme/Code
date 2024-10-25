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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> ans;
        deque<TreeNode*> que;
        if (root != NULL)
            que.push_back(root);
        else
            return ans;
        while (!que.empty())
        {
            int size = que.size();
            vector<int> temp;
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                temp.push_back(node->val);
                que.pop_front();
                if (node->left != NULL)
                    que.push_back(node->left);
                if (node->right != NULL)
                    que.push_back(node->right);
            }ans.push_back(temp);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};