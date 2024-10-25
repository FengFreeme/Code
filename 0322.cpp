#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
    /*
    int coinChange(vector<int>& coins, int amount) 
    {
        int m = coins.size();
        if (amount == 0)
            return 0;
        
        //* 第一个初始化 方便求最小
        //* 第二个初始化 方便求有效的最小值
        
        vector<vector<int>> dp(m + 1, vector<int>(amount + 1, INT_MAX - 1));
        //凑足金额为0所需的硬币数为0
        for (int i = 1; i <= m; i++)
            dp[i][0] = 0;
        for (int i = 1; i <= m; i++)
        {
            int value = coins[i - 1];
            for (int j = 1; j <= amount; j++)
            {
                if (j < value)
                    dp[i][j] = dp[i - 1][j];
                else if (j >= value)
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - value] + 1);
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        if (dp[m][amount] != INT_MAX - 1)
            return dp[m][amount];
        else
            return -1;
    }
    */
    /*
    int coinChange(vector<int>& coins, int amount)
    {
        int m = coins.size();
        if (coins.empty())
            return -1;
        vector<int> dp(amount + 1, INT_MAX - 1);
        //确定好初始化
        dp[0] = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = coins[i]; j <= amount; j++)
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            for (int j = 1; j <= amount; j++)
                cout << dp[j] << " ";
            cout << endl;
        }
        if (dp[amount] != INT_MAX - 1)
            return dp[amount];
        else
            return -1;
    }
    */
    int coinChange(vector<int>& coins, int amount)
    {
        int m = coins.size();
        vector<vector<int>> dp(m + 1, vector<int>(amount + 1, INT_MAX - 1));
        for (int i = 1; i <= m; i++)
            dp[i][0] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (j < coins[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else if (j >= coins[i - 1])
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        if (dp[m][amount] != INT_MAX - 1)
            return dp[m][amount];
        else
            return -1;
    }
};

int main()
{
    vector<int> coins = { 1, 2, 5 };
    int amount = 11;

    Solution S;
    S.coinChange(coins, amount);

    return 0;
}