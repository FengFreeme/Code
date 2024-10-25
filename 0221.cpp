#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution 
{
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int MaxEdge = 0;
        if (matrix[0][0] == '0')
            dp[0][0] = 0;
        else
            dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '0')
                    dp[i][j] = 0;
                else
                {
                    if (i - 1 >= 0 && j - 1 >= 0)
                        dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    else
                        dp[i][j] = 1;
                }
                MaxEdge = max(MaxEdge, dp[i][j]);
            }
        }
        return pow(MaxEdge, 2);
    }
};

int main()
{
    vector<vector<char>> matrix = { {'0', '0', '1', '0'},{'0', '1', '1', '1'},{'1', '1', '1', '1'},{'0', '1', '1', '1'} };

    Solution S;
    S.maximalSquare(matrix);

    return 0;
}