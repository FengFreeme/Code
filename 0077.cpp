#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    // 回溯
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) 
    {
        backtracking(n, k, 1);
        return ans;
    }
    void backtracking(int n, int k, int startIndex)
    {
        if (path.size() == k)
        {
            ans.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++)
        {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
    void backtracking(int n, int k, int startIndex)
    {
        if (path.size() == k)
        {
            ans.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++)
        {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
    void backtracking(int n, int k, int startIndex)
    {
        if (path.size() == k)
        {
            ans.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++)
        {
            path.push_back(i);
            // n - 1 集合中剩余元素, k - path.size() 还需要的元素
            if(n - i >= k - path.size())
                backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
};


int main()
{
    int n = 4, k = 2;

    Solution S;
    S.combine(n, k);

    return 0;
}