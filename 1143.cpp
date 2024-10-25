#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m = text1.size(), n = text2.size();
        if (m == 0 || n == 0)
            return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxLength = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                //cout << dp[i][j] << " ";
                maxLength = max(maxLength, dp[i][j]);
            }
            //cout << endl;
        }
        return maxLength;
    }
};

int main()
{
    string text1 = "abcde", text2 = "ace";
    Solution S;
    S.longestCommonSubsequence(text1, text2);

    return 0;
}