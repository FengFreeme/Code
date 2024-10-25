#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int integerBreak(int n) 
    {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        //cout << dp[2] << " ";
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
            }
            //cout << dp[i] << " ";
        }
        return dp[n];
    }
};

int main()
{
    int n = 10;
    Solution S;
    S.integerBreak(n);

    return 0;
}