#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution 
{
public:
    
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        //假设符号为正的数字总和为x
        if (abs(target) > sum)
            return 0;
        if ((sum + target) % 2 == 1)
            return 0;
        int x = (sum + target) / 2;
        int m = nums.size();
        vector<vector<int>> dp(m + 1, vector<int>(x + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j <= x; j++)        //j=0也考虑进去，因为有可能等于0
            {
                if (j < nums[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else if (j >= nums[i - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[m][x];
    }
    
    /*
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        //假设符号为正的数字总和为x
        if (abs(target) > sum)
            return 0;
        if ((sum + target) % 2 == 1)
            return 0;
        int x = (sum + target) / 2;
        int m = nums.size();
        vector<int> dp(x + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = x; j >= nums[i-1]; j--)
            {
                dp[j] = dp[j] + dp[j - nums[i - 1]];
            }
            for (int j = 1; j <= x; j++)
            {
                cout << dp[j] << " ";
            }
            cout << endl;
        }
        return dp[x];
    }
    */
};

int main()
{
    vector<int> nums = { 0,0,0,0,0,0,0,0,1 };
    int target = 1;

    Solution S;
    S.findTargetSumWays(nums, target);

    return 0;
}