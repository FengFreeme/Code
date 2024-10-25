#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 == 0 || len2 == 0)
            return 0;
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
        int maxLength = 0;
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                cout << dp[i][j] << " ";
                maxLength = max(dp[i][j], maxLength);
            }
            cout << endl;
        }
        return maxLength;
    }
};

int main()
{
    vector<int> nums1 = { 0,0,0,0,0 };
    vector<int> nums2 = { 0,0,0,0,0 };

    Solution S;
    S.findLength(nums1, nums2);

    return 0;
}