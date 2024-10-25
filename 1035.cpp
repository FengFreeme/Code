#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        int len1 = nums1.size(), len2 = nums2.size();
        if (len1 == 0 || len2 == 0)
            return 0;
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (nums1[i - 1] != nums2[j - 1])
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                else if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, max(dp[i - 1][j], dp[i][j - 1]));
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        return dp[len1][len2];
    }
};

int main()
{
    vector<int> nums1 = { 1,3,7,1,7,5 }, nums2 = { 1,9,2,5,1 };

    Solution S;
    S.maxUncrossedLines(nums1, nums2);

    return 0;
}