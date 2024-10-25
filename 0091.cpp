#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
    /*
    int numDecodings(string s) 
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                if (i >= 1 && (s[i - 1] == '0' || s[i - 1] > '2'))      //如1001 1305
                    return 0;
                else if (i == 0)
                    dp[i + 1] = 0;
                else if (i == 1)
                    dp[i + 1] = dp[i];
                else if (i >= 2)
                    dp[i + 1] = dp[i - 1];           
            }     
            else        //不等于'0'的情况
            {
                if(i == 0)
                    dp[i + 1] = 1;
                else if (i >= 1 && s[i - 1] == '0')      //如11106
                    dp[i + 1] = dp[i];
                else if (i >= 1 && ((s[i - 1] >= '2' && s[i] > '6') || s[i - 1] > '2'))     //如132
                    dp[i + 1] = dp[i];
                else if(i == 1)     //如111
                    dp[i + 1] = dp[i] + 1; 
                else                //如111
                    dp[i + 1] = dp[i] + dp[i - 1];

            }
        }
        return dp[n];
    }
    */
    int numDecodings(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;
        int prev = s[0] - '0';
        if (!prev)
            return 0;
        if (n == 1)
            return 1;
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; i++)
        {
            int cur = s[i - 1] - '0';
            if ((prev == 0 || prev > 2) && cur == 0)
                return 0;
            if ((prev < 2 && prev > 0) || prev == 2 && cur < 7)
            {
                if (cur)
                    dp[i] = dp[i - 2] + dp[i - 1];
                else
                    dp[i] = dp[i - 2];
            }
            else
                dp[i] = dp[i - 1];
            prev = cur;
        }
        return dp[n];
    }
};

int main()
{
    string s = "230";
    Solution S;
    S.numDecodings(s);

    return 0;
}