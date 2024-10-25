#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    /*
    * // 动态规划
    int maxProfit(vector<int>& prices) 
    {
        int len = prices.size();
        if (len == 0)
            return 0;
        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        //cout << dp[0][0] << " ";
        dp[0][1] = 0;
        //cout << dp[0][1] << endl;
        int maxprofit = 0;
        for (int i = 1; i < len; i++)
        {
            if (prices[i] >= prices[i - 1])
            {
                dp[i][0] = max(dp[i - 1][0], -prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            }
            else if (prices[i] < prices[i - 1])
            {
                if (dp[i - 1][1] > 0)
                {
                    maxprofit += dp[i - 1][1];
                }
                dp[i][0] = -prices[i];
                dp[i][1] = 0;
            }
            //cout << dp[i][0] << " " << dp[i][1] << endl;
        }
        if (dp[len - 1][1] > 0)
        {
            maxprofit += dp[len - 1][1];
        }
        //cout << maxprofit << endl;
        return maxprofit;
    }
    
    int maxProfit(vector<int>& prices)
    {
        int len = prices.size();
        if (len == 0)
            return 0;
        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        //cout << dp[0][0] << " ";
        dp[0][1] = 0;
        //cout << dp[0][1] << endl;
        for (int i = 1; i < len; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            //cout << dp[i][0] << " " << dp[i][1] << endl;
        }
        return dp[len - 1][1];
    }
    */
    // 贪心算法 贪：如果当前元素比上一个元素小，那就更新，寻找新的商机
    int maxProfit(vector<int>& prices) 
    {
        int len = prices.size();
        int maxprofit = 0;
        int profit = 0;
        int preprice = prices[0];
        for (int i = 1; i < len; i++)
        {
            if (prices[i] <= prices[i - 1])
            {
                preprice = prices[i];
                maxprofit = maxprofit + profit;
                profit = 0;
            }
            else if (prices[i] > prices[i - 1] && i == len - 1)
            {
                profit = prices[i] - preprice;
                maxprofit = maxprofit + profit;
            }
            else if (prices[i] > prices[i - 1])
            {
                profit = prices[i] - preprice;
            }
        }
        return maxprofit;
    }
};

int main()
{
    vector<int> prices = { 3,2,6,5,0,3 };

    Solution S;
    S.maxProfit(prices);

    return 0;
}