#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int numDistinct(string s, string t) 
    {
        int  len1 = s.size(), len2 = t.size();
        if (len1 == 0 || len2 == 0)
            return 0;
        vector<vector<uint64_t>> dp(len2 + 1, vector<uint64_t>(len1 + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= len1; i++)
            dp[0][i] = 1;
        for (int j = 1; j <= len2; j++)
            dp[j][0] = 0;
        for (int i = 1; i <= len2; i++)
        {
            for (int j = i; j <= len1; j++)
            {
                if (t[i - 1] == s[j - 1])
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]);
                else
                    dp[i][j] = dp[i][j - 1];
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        return dp[len2][len1];
    }
};

int main()
{
    string s = "babgbag", t = "bag";

    Solution S;
    S.numDistinct(s, t);

    return 0;
}