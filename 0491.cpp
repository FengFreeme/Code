#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        if (nums.size() <= 1)
            return ans;
        backtracking(nums, 0);

        return ans;
    }
    // 用unordered_set去重
    // 1. 确定参数
    void backtracking(vector<int> nums, int startIndex)
    {
        // 2. 确定终止条件
        if (path.size() >= 2)
            ans.push_back(path);
        if (startIndex >= nums.size())
            return;
        // 3. 单次递归处理
        // 使用set对本层元素进行去重，不同层会重新记录
        unordered_set<int> uset; 
        for (int i = startIndex; i < nums.size(); i++)
        {
            if((path.size() == 0 || nums[i] >= path.back()) && uset.find(nums[i]) == uset.end())
            {
                // 记录元素在本层已经使用过，不能再次使用
                uset.insert(nums[i]);
                path.push_back(nums[i]);
                backtracking(nums, i + 1);
                path.pop_back();
            }
        }
        return;
    }
};

int main()
{
    vector<int> nums = { 1,2,3,1,1,1 };

    Solution S;
    S.findSubsequences(nums);

    return 0;
}