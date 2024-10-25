#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    int sum = 0;
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        backtracking(k, n, 1);

        return ans;
    }
    void backtracking(int k, int n, int startIndex)
    {
        if (path.size() == k)
        {
            if(sum == n)
                ans.push_back(path);
            return;
        }
        if (path.size() == k - 1 && n - sum < startIndex)
        {
            return;
        }
        for (int i = startIndex; i <= 9; i++)
        {
            path.push_back(i);
            sum = sum + i;
            backtracking(k, n, i + 1);
            sum = sum - i;
            path.pop_back();
        }
    }
    void backtracking(int k, int n, int startIndex)
    {
        if (path.size() == k)
        {
            if (sum == n)
                ans.push_back(path);
            return;
        }
        if (sum >= n)
        {
            return;
        }
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++)
        {
            path.push_back(i);
            sum = sum + i;
            backtracking(k, n, i + 1);
            sum = sum - i;
            path.pop_back();
        }
    }
};

int main()
{
    int k = 3, n = 7;
    Solution S;
    S.combinationSum3(k, n);

    return 0;
}