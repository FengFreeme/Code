#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

class Solution 
{
public:
    /*
    bool canPartition1(vector<int>& nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        int target = sum / 2, n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;
        for (int i = 1; i <= n; i++)
        {
            int w = nums[i - 1];
            for (int j = 1; j <= target; j++)
            {
                if (j < w)
                    dp[i][j] = dp[i - 1][j];
                else if(j >= w)
                //放与不放
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - w];
            }
        }
        return dp[n][target];
    }
    */
    /*
    bool canPartition(vector<int>& nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        int m = nums.size(), n = sum / 2;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                //不放入该数字
                if (j < nums[i - 1])
                    dp[i][j] = dp[i - 1][j];
                //放入数字
                else if (j >= nums[i - 1])
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        if (dp[m][n] == n)
            return true;
        else
            return false;
    }
    */
    /*
    bool canPartition(vector<int>& nums)
    {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2 == 1)
            return false;
        int m = nums.size(), n = target / 2;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j < nums[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else if (j >= nums[i - 1])
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        if (dp[m][n] == n)
            return true;
        else
            return false;
    }
    */
    bool canPartition(vector<int>& nums)
    {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2 == 1)
            return false;
        int m = nums.size(), n = target / 2;
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= m; i++)
        {
            for (int j = n; j >= nums[i - 1]; j--)
            {           
                dp[j] = max(dp[j], dp[j - nums[i - 1]] + nums[i - 1]);
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        if (dp[n] == n)
            return true;
        else
            return false;
    }
};

int main()
{
    vector<int> nums = { 1, 5, 10, 6 };
    Solution S;
    //S.canPartition1(nums);
    S.canPartition(nums);

    return 0;
}