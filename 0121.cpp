#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int len = prices.size();
        if (len == 0)
            return 0;
        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        cout << dp[0][0] << " ";
        dp[0][1] = 0;
        cout << dp[0][1] << endl;
        for (int i = 1; i < len; i++)
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            cout << dp[i][0] << " ";
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
            cout << dp[i][1] << endl;
        }
        return dp[len - 1][1];
    }
};

int main()
{
    vector<int> prices = { 2,4,1 };

    Solution S;
    S.maxProfit(prices);

    return 0;
}