#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int len = prices.size();
        if (len == 0)
            return 0;
        vector<vector<int>> dp(len, vector<int>(2, 0));
        //¬Ú»Îπ…∆±
        dp[0][0] = -prices[0] - fee;
        for (int i = 1; i < len; i++)
        {
            //¬Ú»Î
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            //cout << dp[i][0] << " " << dp[i][1] << endl;
        }
        return dp[len - 1][1];
    }
};

int main()
{
    vector<int> prices = { 1,3,7,5,10,3 };
    int fee = 3;

    Solution S;
    S.maxProfit(prices, fee);

    return 0;
}