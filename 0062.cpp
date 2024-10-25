#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        if (m == 1 || n == 1)
            return 1;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int j = 2; j <= n; j++)
            dp[1][j] = 1;
        for (int i = 2; i <= m; i++)
            dp[i][1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(i >= 2 && j >= 2)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        return dp[m][n];
    }
};

int main()
{
    int m = 3, n = 7;
    Solution S;
    S.uniquePaths(m, n);

    return 0;
}