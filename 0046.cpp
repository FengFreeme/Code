#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used = vector<bool>(6, false);
    vector<vector<int>> permute(vector<int>& nums) 
    {
        backtracking(nums);

        return ans;
    }
    // 1. 确定参数
    void backtracking(vector<int> nums)
    {
        // 2. 终止条件
        if (path.size() == nums.size())
        {
            ans.push_back(path);
            return;
        }
        // 3. 单次递归处理
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == false)
            {
                path.push_back(nums[i]);
                used[i] = true;
                backtracking(nums);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};


int main()
{
    vector<int> nums = { 1, 2, 3 };
    Solution S;
    S.permute(nums);

    return 0;
}