#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution 
{
public:
    /*
    int lastStoneWeightII(vector<int>& stones)
    {
        int weights = accumulate(stones.begin(), stones.end(), 0);
        int t_weight = weights / 2;
        int m = stones.size();
        vector<vector<int>> dp(m + 1, vector<int>(t_weight + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= t_weight; j++)
            {
                if (j < stones[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else if (j >= stones[i - 1])
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        return (weights - dp[m][t_weight]) - dp[m][t_weight];
    }
    */
    int lastStoneWeightII(vector<int>& stones)
    {
        int weights = accumulate(stones.begin(), stones.end(), 0);
        int t_weight = weights / 2;
        int m = stones.size();
        vector<int> dp(t_weight + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            for (int j = t_weight; j >= stones[i-1]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i - 1]] + stones[i - 1]);
                //cout << dp[i][j] << " ";
            }
            /*for (int j = 1; j <= t_weight; j++)
            {
                cout << dp[j] << " ";
            }
            cout << endl;*/
        }
        return (weights - dp[t_weight]) - dp[t_weight];
    }
};

int main()
{
    vector<int> stones = { 31,26,33,21,40 };

    Solution S;
    S.lastStoneWeightII(stones);

    return 0;
}