#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    /*
    int maxProfit(vector<int>& prices) 
    {
        int len = prices.size();
        if (len == 0)
            return 0;
        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < len; i++)
        {
            //Âò
            if(i < 2)
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            else 
                dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i]);
            //Âô
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            //cout << dp[i][0] << " " << dp[i][1] << endl;
        }
        return dp[len - 1][1];
    }
    */
    int maxProfit(vector<int>& prices)
    {
        int len = prices.size();
        if (len == 0)
            return 0;
        vector<vector<int>> dp(len, vector<int>(4, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < len; i++)
        {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3] - prices[i], dp[i - 1][1] - prices[i]));
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
            cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << endl;
        }
        return max(dp[len - 1][3], max(dp[len - 1][1], dp[len - 1][2]));
    }
};

int main()
{
    vector<int> prices = { 1,2,3,0,2 };

    Solution S;
    S.maxProfit(prices);

    return 0;
}