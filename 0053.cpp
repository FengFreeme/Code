#include<iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    /*
    * // 动态规划
    int maxSubArray(vector<int>& nums) 
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        vector<int> dp(len + 1, 0);
        int maxNum = -INT_MAX;

        for (int i = 1; i <= len; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
            //cout << dp[i] << " ";
            maxNum = max(dp[i], maxNum);
        }
        //cout << endl << maxNum;
        return maxNum;
    }
    */
    // 贪心算法 记住贪什么
    int maxSubArray(vector<int>& nums) 
    {
        int ans = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            ans = max(sum, ans);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };

    Solution S;
    S.maxSubArray(nums);

    return 0;
}