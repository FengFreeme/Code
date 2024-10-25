#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int longestPalindromeSubseq(string s) 
    {
        int len = s.size();
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
        int maxLength = 0;
        for (int i = len; i >= 1; i--)
        {
            for (int j = i; j <= len; j++)
            {
                if (s[i - 1] != s[j - 1])
                {
                    if (abs(i - j) == 1)
                        dp[i][j] += 1;
                    else
                        dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
                else if (s[i - 1] == s[j - 1])
                {
                    if (abs(i - j) == 0)
                        dp[i][j] = dp[i][j] + 1;
                    else if(abs(i - j) == 1)
                        dp[i][j] = dp[i][j] + 2;
                    else
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                maxLength = max(maxLength, dp[i][j]);
            }
        }
        //cout << maxLength;
        return maxLength;
    }
};

int main()
{
    string s = "bbbab";

    Solution S;
    S.longestPalindromeSubseq(s);

    return 0;
}