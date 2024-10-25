#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//图的题目
class Solution 
{
public:
    int shortestBridge(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> points;
        bool flipped = false;
        //DFS寻找第一个完整的岛屿
        for (int i = 0; i < m; i++)
        {
            if (flipped)
                break;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    DFS(points, grid, m, n, i, j);
                    flipped = true;
                    break;
                }
            }
        }
        //BFS寻找第二个岛屿
        int x, y;
        int level = 0;
        while (!points.empty())         //先访问所有的邻接顶点
        {
            level++;
            int n_points = points.size();
            while (n_points--)
            {
                auto [r, c] = points.front();   //返回队列中的第一个元素
                points.pop();       //删除队列第一个元素
                for (int k = 0; k < 4; k++)
                {
                    x = r + direction[k];
                    y = c + direction[k + 1];
                    if (x >= 0 && y >= 0 && x < m && y < n)
                    {
                        if (grid[x][y] == 2)        //已经访问过，跳过
                            continue;
                        if (grid[x][y] == 1)        //找到了另一个岛屿
                            return level;
                        points.push({ x, y });      //把接下来要访问的邻接顶点放进去
                        grid[x][y] = 2;             //标记已访问
                    }
                }
            }
        }
        return 0;
    }
    //辅函数 深度优先遍历
    void DFS(queue<pair<int, int>>& points, vector<vector<int>>& grid, int m, int n, int i, int j)
    {
        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 2)
            return;
        if (grid[i][j] == 0)    
        {
            points.push({ i, j });      //记录已知岛屿的邻接顶点
            return;
        }
        grid[i][j] = 2;     //把遇到的连接的岛屿标记
        DFS(points, grid, m, n, i - 1, j);
        DFS(points, grid, m, n, i + 1, j);
        DFS(points, grid, m, n, i, j - 1);
        DFS(points, grid, m, n, i, j + 1);
    }
private:
    vector<int> direction = { -1, 0, 1, 0, -1 };
};

int main()
{
    vector<vector<int>> grid = { {1, 1, 1, 1, 1},{1, 0, 0, 0, 1},{1, 0, 1, 0, 1},{1, 0, 0, 0, 1},{1, 1, 1, 1, 1} };
    Solution S;
    S.shortestBridge(grid);

    return 0;
}