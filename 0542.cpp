#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size(), n = mat[0].size();
        if (m == 0 || n == 0)
            return {};
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                    dp[i][j] = 0;
                else
                {
                    if (j > 0)
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1); //向左
                    if (i > 0)
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); //向上
                }
            }
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (j < n - 1)
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1); //向右
                if (i < m - 1)
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1); //向下
            }
        }
        return dp;
    }

};

int main()
{
    vector<vector<int>> mat = { {0, 0, 0},{0, 1, 0 }, {1, 1, 1} };

    Solution S;
    S.updateMatrix(mat);

    return 0;
}