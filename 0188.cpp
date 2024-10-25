#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int len = prices.size();
        int n = 2 * k;
        if (len == 0)
            return 0;
        vector<vector<int>> dp(len, vector<int>(n + 1));
        for (int i = 1; i <= n; i += 2)
            dp[0][i] = -prices[0];
        for (int i = 1; i < len; i++)
        {
            dp[i][0] = dp[i - 1][0];
            for (int j = 1; j <= n; j++)
            {
                if (j % 2 == 1)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        return dp[len - 1][n];
    }
};

int main()
{
    vector<int> prices = { 3,2,6,5,0,3 };
    int k = 2;

    Solution S;
    S.maxProfit(k, prices);

    return 0;
}