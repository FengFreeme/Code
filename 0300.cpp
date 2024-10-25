#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        vector<int> dp(len + 1, 1);
        int maxLength = 1;
        //cout << dp[1] << " ";
        for (int j = 2; j <= len; j++)
        {
            for (int i = j - 1; i >= 1; i--)
            {
                if (nums[j - 1] > nums[i - 1])
                {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            //cout << dp[j] << " ";
            maxLength = max(maxLength, dp[j]);
        }
        return maxLength;
    }
};

int main()
{
    vector<int> nums = { 0,1,0,3,2,3 };
    Solution S;
    S.lengthOfLIS(nums);

    return 0;
}