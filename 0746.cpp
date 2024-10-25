#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        vector<int> dp(n + 1);
        cout << dp[0] << " " << dp[1] << " ";
        for (int i = 2; i <= n; i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
            cout << dp[i] << " ";
        }
        return dp[n];
    }
};

int main()
{
    vector<int> cost = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };

    Solution S;
    S.minCostClimbingStairs(cost);

    return 0;
}