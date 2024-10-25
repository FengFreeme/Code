#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int countSubstrings(string s) 
    {
        int len = s.size();
        vector<vector<bool>> dp(len + 1, vector<bool>(len + 1, false));
        int ans = 0;
        for (int i = len; i > 0; i--)
        {
            for (int j = i; j <= len; j++)
            {
                if (s[i - 1] == s[j - 1])
                {
                    if (i == j)
                    {
                        dp[i][j] = true;
                        ans++;
                    }
                    else if (abs(i - j) == 1)
                    {
                        dp[i][j] = true;
                        ans++;
                    }
                    else if (dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                        ans++;
                    }
                }
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        //cout << ans;
        return ans;
    }
};

int main()
{
    string s = "abc";
    
    Solution S;
    S.countSubstrings(s);

    return 0;
}