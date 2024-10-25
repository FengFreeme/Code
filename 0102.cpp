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
            // �ǵ�ǰ�㣬�������뵽��ǰ����
            if (curLevel == t1.level)
            {
                temp.push_back(t1.root->val);
            }
            // �������£�����һ������뵽��������в���������б������һ���㣬������curLevel
            else
            {
                ans.push_back(temp);
                // ���
                temp.resize(0);
                temp.push_back(t1.root->val);
                curLevel = t1.level;
            }
            que.pop_front();
            // ����Ӧ����һ����������
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
    // �����ķ���
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
    // �ݹ鷨
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
        // ͨ���������±꣩ȷ���ŵ�λ��
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