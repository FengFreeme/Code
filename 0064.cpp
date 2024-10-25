#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        if (n == 0 || m == 0)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
                else if (i - 1< 0 && j - 1 >= 0)
                {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                }
                else if (i - 1 >= 0 && j - 1 < 0)
                {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
    //ÊéÉÏÑ¹Ëõ¿Õ¼ä
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[j] = grid[i][j];
                else if (i == 0)
                    dp[j] = dp[j - 1] + grid[i][j];
                else if (j == 0)
                    dp[j] = dp[j] + grid[i][j];
                else
                    dp[j] = min(dp[j], dp[j - 1] + grid[i][j]);
            }
        }
        return dp[n - 1];
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    Solution S;
    S.minPathSum(grid);

    return 0;
}