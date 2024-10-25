#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    /*
    bool isSubsequence(string s, string t) 
    {
        int len1 = s.size(), len2 = t.size();
        if (len1 == 0)
            return true;
        if (len2 == 0)
            return false;
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        for (int i = 0; i <= len2; i++)
            dp[0][i] = true;
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] && true;
                else
                    dp[i][j] = dp[i][j - 1];
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        return dp[len1][len2];
    }
    */
    bool isSubsequence(string s, string t)
    {
        int len1 = s.size(), len2 = t.size();
        if (len1 == 0)
            return true;
        if (len2 == 0)
            return false;
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = dp[i][j - 1];
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return (len1 == dp[len1][len2]);
    }
};

int main()
{
    string s = "axc", t = "ahbgdc";

    Solution S;
    S.isSubsequence(s, t);

    return 0;
}