#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    /*
    int change(int amount, vector<int>& coins) 
    {
        int m = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        //求组合数
        for (int i = 1; i <= m; i++)                     //遍历物品
        {
            for (int j = 1; j <= amount; j++)   //遍历背包
            {
                if (j >= coins[i - 1])
                {
                    dp[j] = dp[j] + dp[j - coins[i - 1]];
                }
                cout << dp[j] << " ";
            }
            cout << endl;
        }
        return dp[amount];
    }
    */
    /*
    int change(int amount, vector<int>& coins)
    {
        int m = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        //求排列数
        for (int j = 0; j <= amount; j++)           //遍历背包
        {
            for (int i = 1; i <= m; i++)             //遍历物品
            {
                if (j >= coins[i - 1])
                    dp[j] += dp[j - coins[i -1]];
                cout << dp[j] << " ";
            }
            cout << endl;
        }
        return dp[amount];
    }
    */
    /*
    * //二维数组
    int change(int amount, vector<int>& coins)
    {
        int m = coins.size();
        vector<vector<int>> dp(m + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= m; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if (j < coins[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else if (j >= coins[i - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        return dp[m][amount];
    }
    */
    int change(int amount, vector<int>& coins)
    {
        int m = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = coins[i - 1]; j <= amount; j++)
            {
                dp[j] = dp[j] + dp[j - coins[i - 1]];
            }
            /*for (int j = 0; j <= amount; j++)
                cout << dp[j] << " ";
            cout << endl;*/
        }
        return dp[amount];
    }
};

int main()
{
    int amount = 5;
    vector<int>coins = { 1, 2, 5 };
    Solution S;
    S.change(5, coins);

    return 0;
}