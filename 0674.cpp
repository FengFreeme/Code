#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        vector<int> dp(len + 1, 1);
        int maxLength = 1;
        //cout << dp[1] << " ";
        for (int j = 2; j <= len; j++)
        {
            if (nums[j - 1] > nums[j - 2])
                dp[j] = dp[j - 1] + 1;
            maxLength = max(maxLength, dp[j]);
            //cout << dp[j] << " ";
        }
        return maxLength;
    }
};

int main()
{
    vector<int> nums = { 2,2,2,2,2 };

    Solution S;
    S.findLengthOfLCIS(nums);

    return 0;
}