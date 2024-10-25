#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution 
{
public:
    /*
    //动态规划 
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        if (nums.size() < 3)
            return 0;
        int n = nums.size();
        vector<int> dp(n, 0);
        for (int i = 2; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                dp[i] = dp[i - 1] + 1;
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
    */
    //动态规划 自己再写一遍
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0;
        vector<int> dp(n, 0);
        for (int i = 2; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                dp[i] = dp[i - 1] + 1;
            }
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

int main()
{
    vector<int> nums = { 1,2,3,4,5};

    Solution S;
    S.numberOfArithmeticSlices(nums);

    return 0;
}