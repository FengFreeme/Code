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
    struct Tree
    {
        TreeNode* root;
        int level = 0;
    };
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        deque<Tree> que;
        vector<vector<int>> ans;
        vector<int> temp;
        Tree T;
        T.root = root;
        int curLevel = 0;
        if (root != NULL)
            que.push_back(T);
        else
            return ans;
        while (!que.empty())
        {
            Tree t1 = que.front();
            // 是当前层，将结点加入到当前数组
            if (curLevel == t1.level)
            {
                temp.push_back(t1.root->val);
            }
            // 层数更新，将上一层结点加入到结果数组中并清空数组中保存的上一层结点，并更新curLevel
            else
            {
                ans.push_back(temp);
                // 清空
                temp.resize(0);
                temp.push_back(t1.root->val);
                curLevel = t1.level;
            }
            que.pop_front();
            // 将相应的下一层结点加入队列
            Tree t2;
            if (t1.root->left != NULL)
            {
                t2.root = t1.root->left;
                t2.level = t1.level + 1;
                que.push_back(t2);
            }
            if (t1.root->right != NULL)
            {
                t2.root = t1.root->right;
                t2.level = t1.level + 1;
                que.push_back(t2);
            }
        }
        if (temp.size() != 0)
            ans.push_back(temp);

        return ans;
    }
    */
    // 更简洁的方法
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        deque<TreeNode*> que;
        vector<vector<int>> ans;
        
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
                if (node->left != NULL)
                    que.push_back(node->left);
                if (node->right != NULL)
                    que.push_back(node->right);
                que.pop_front();
            }
            ans.push_back(temp);
        }
        return ans;
    }
    // 递归法
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        int depth = 0;
        order(root, ans, depth);

        return ans;
    }
    void order(TreeNode* cur, vector<vector<int>>& ans, int depth)
    {
        if (cur == NULL)
            return;
        if (ans.size() == depth)
            ans.push_back(vector<int>());
        // 通过层数（下标）确定放的位置
        ans[depth].push_back(cur->val);
        order(cur->left, ans, depth + 1);
        order(cur->right, ans, depth + 1);
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* node = root;
    node->right = new TreeNode(2);
    node = node->right;
    node->left = new TreeNode(3);

    Solution S;
    S.levelOrder(root);

    return 0;
}