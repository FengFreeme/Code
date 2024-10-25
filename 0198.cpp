#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    /*
    //动态规划
    int rob(vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++)
            dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);        //nums[i-1]即第i个房子
        return dp[n];
    }
    */
    /*
    //自己写的动态规划+压缩空间，和书上也差不多
    int rob(vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int ans = 0;
        int temp = 0;
        int a = nums[0], b = 0;         //a = dp[i-1]; b = dp[i-2]
        for (int i = 1; i < n; i++)
        {
            a > b + nums[i] ? ans = a : ans = b + nums[i];
            b = a;
            a = ans;
        }
        return ans;
    }
    */
    int rob(vector<int>& nums)
    {
        int m = nums.size();
        vector<int> dp(m + 1, 0);
        dp[0] = 0, dp[1] = nums[0];
        for (int j = 2; j <= m; j++)
        {
            dp[j] = max(dp[j - 1], dp[j - 2] + nums[j - 1]);
            //cout << dp[j] << " ";
        }
        return dp[m];
    }
};

int main()
{
    vector<int> nums = { 1,2,3,1 };
    Solution S;

    S.rob(nums);

    return 0;
}