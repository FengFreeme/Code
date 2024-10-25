#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int m = heights.size(), n = heights[0].size();
        if (m == 0 || n == 0)
            return {};
        vector<vector<int>> ans;
        vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));
        vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));
        //��̫ƽ����ߴ����󣨱߽磩����������
        for (int i = 0; i < m; i++)
        {
            DFS(heights, can_reach_p, i, 0);        //��߽�
            DFS(heights, can_reach_a, i, n - 1);    //�ұ߽�
        }
        for (int i = 0; i < n; i++)
        {
            DFS(heights, can_reach_p, 0, i);        //�ϱ߽�
            DFS(heights, can_reach_a, m - 1, i);    //�±߽�
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (can_reach_a[i][j] && can_reach_p[i][j])
                    ans.push_back({ i, j });
            }
        }
        return ans;
    }
    void DFS(const vector<vector<int>>& matrix, vector<vector<bool>>& can_reach, int r, int c)
    {
        if (can_reach[r][c])
            return;
        can_reach[r][c] = true;
        int x, y;
        for (int i = 0; i < 4; i++)
        {
            x = r + direction[i], y = c + direction[i + 1];
            if (x >= 0 && x < matrix.size() &&
                y >= 0 && y < matrix[0].size() &&
                matrix[r][c] <= matrix[x][y])
                DFS(matrix, can_reach, x, y);
               
        }
    }
private:
    vector<int> direction{ -1, 0, 1, 0, -1};
};

class Solution
{
public:
    //�Լ���΢д��һ�£������Ϸ�����
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        int m = heights.size(), n = heights[0].size();
        if (m == 0 || n == 0)
            return {};
        vector<vector<int>> ans;
        vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));
        vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++)
        {
            DFS(heights, can_reach_p, i, 0);
            DFS(heights, can_reach_a, i, n - 1);
        }
        for (int i = 0; i < n; i++)
        {
            DFS(heights, can_reach_p, 0, i);
            DFS(heights, can_reach_a, m - 1, i);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (can_reach_p[i][j] && can_reach_a[i][j])
                    ans.push_back({ i, j });
            }
        }
        return ans;
    }
    void DFS(const vector<vector<int>>& matrix, vector<vector<bool>>& can_reach, int r, int c)
    {
        if (can_reach[r][c])        //˵���Ѿ����㣬���ü����ݹ���
            return;
        can_reach[r][c] = true;
        for (int i = 0; i < 4; i++)
        {
            int x = r + direction[i], y = c + direction[i + 1];
            if (x >= 0 && x < matrix.size() &&
                y >= 0 && y < matrix[0].size() &&
                matrix[x][y] >= matrix[r][c])
                DFS(matrix, can_reach, x, y);
        }
    }
private:
    vector<int> direction{ -1, 0, 1, 0, -1 };
};