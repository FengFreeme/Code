#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1)
            return 0;
        if (m == 1)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[0][j] == 1)        //有障碍，走不通，直接归零
                    return 0;
            }
            return 1;
        }
        else if (n == 1)
        {
            for (int i = 0; i < m; i++)
            {
                if (obstacleGrid[i][0] == 1)        
                    return 0;
            }
            return 1;
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        bool ObstacleFlag = false;
        for (int j = 2; j <= n; j++)
        {
            if(obstacleGrid[0][j-1] == 1)
                ObstacleFlag = true;
            if(!ObstacleFlag)
                dp[1][j] = 1;
            else
                dp[1][j] = 0;
        }
        ObstacleFlag = false;
        for (int i = 2; i <= m; i++)
        {
            if (obstacleGrid[i-1][0] == 1)
                ObstacleFlag = true;
            if (!ObstacleFlag)
                dp[i][1] = 1;
            else
                dp[i][1] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i >= 2 && j >= 2)
                {
                    if (obstacleGrid[i - 1][j - 1] == 1)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        return dp[m][n];
    }
};

int main()
{
    vector<vector<int>> obstacleGrid = { {0},{ 1 } };
    Solution S;
    S.uniquePathsWithObstacles(obstacleGrid);

    return 0;
}