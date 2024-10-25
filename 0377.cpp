#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        int m = nums.size();
        vector<unsigned long int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= target; j++)
        {
            for (int i = 1; i <= m; i++)
            {
                if (j >= nums[i - 1])
                {
                    dp[j] = dp[j] + dp[j - nums[i - 1]];
                }
                cout << dp[j] << " ";
            }
            cout << endl;
        }
        return dp[target];
    }
};

int main()
{
    vector<int> nums = { 1, 2, 3 };
    int target = 4;

    Solution S;
    S.combinationSum4(nums, target);

    return 0;
}