#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    /*
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
    */
    int numSquares(int n)
    {
        int m = sqrt(n);
        vector<int> dp(n + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j >= pow(i, 2))
                    dp[j] = min(dp[j], dp[j - pow(i, 2)] + 1);
                //cout << dp[j] << " ";
            }
            //cout << endl;
        }
        return dp[n];
    }
};

int main()
{
    int n = 12;

    Solution S;
    S.numSquares(n);

    return 0;
}