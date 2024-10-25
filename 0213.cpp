#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int rob(vector<int>& nums)
    {
        int m = nums.size();
        if (m == 0)
            return 0;
        if (m == 1)
            return nums[0];
        int result1 = robRange(nums, 0, m - 2);
        int result2 = robRange(nums, 1, m - 1);
        return max(result1, result2);
    }
    
    int robRange(vector<int>& nums, int start, int end)
    {
        if (start == end)
            return nums[start];
        int m = nums.size();
        vector<int> dp(m + 1, 0);
        //注意这儿，初始化错误会导致错误的结果
        dp[start] = 0, dp[start + 1] = nums[start];
        for (int j = start + 2; j <= end + 1; j++)
        {
            dp[j] = max(dp[j - 1], dp[j - 2] + nums[j - 1]);
            cout << dp[j] << " ";
        }
        cout << endl;
        return dp[end + 1];
    }
};

int main()
{
    vector<int> nums = { 1,1,3,6,7,10,7,1,8,5,9,1,4,4,3 };
    Solution S;

    S.rob(nums);

    return 0;
}