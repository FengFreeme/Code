#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    int sum = 0;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);

        return ans;
    }
    // 考虑剪枝优化
    // 1. 确定参数和返回参数
    void backtracking(vector<int> candidates, int target, int startIndex)
    {
        // 2. 终止条件
        if (sum == target)
        {
            ans.push_back(path);
            return;
        }
        else if (sum > target)
            return;
        // 3. 单次递归处理
        // 可以在for中做文章，直接退出循环
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, i);        // 不用i+1了，表示可以重复读取当前的数
            path.pop_back();
            sum -= candidates[i];
        }
        return;
    }
};

int main()
{
    vector<int> candidates = { 2,3,5 };
    int target = 8;

    Solution S;
    S.combinationSum(candidates, target);

    return 0;
}