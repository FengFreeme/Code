#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
    /*
    //ջʵ�������������
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        //m��n�У�local_area��ʱ����
        int m = grid.size(), n = m ? grid[0].size() : 0, local_area, area = 0, x, y;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    local_area = 1;
                    grid[i][j] = 0;         //������ǣ������ѷ��ʹ�
                    stack<pair<int, int>> island;   //�������Ա��������ջ
                    island.push({ i, j });
                    while (!island.empty())
                    {
                        auto [r, c] = island.top();
                        island.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            x = r + direction[k], y = c + direction[k + 1];
                            if (x >= 0 && x < m &&
                                y >= 0 && y < n && grid[x][y] == 1)
                            {
                                grid[x][y] = 0;
                                local_area++;
                                island.push({ x, y });
                            }
                        }
                    }
                    area = max(area, local_area);
                }
            }
        }
        return area;
    }
    
    //�Լ�дһ����Ϥջʵ�������������
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();     //���m = 0��Ϊ����nΪ0
        int local_area, area = 0, x, y;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    stack<pair<int, int>> island;
                    island.push({ i, j });
                    grid[i][j] = 0;
                    local_area = 1;
                    while (!island.empty())
                    {
                        auto [r, c] = island.top();     //top����������Ԫ�ص�ֵ
                        island.pop();
                        for (int k = 0; k < direction.size() - 1; k++)
                        {
                            x = r + direction[k];
                            y = c + direction[k + 1];
                            if (x >= 0 && x < m &&
                                y >= 0 && y < n && grid[x][y] == 1)
                            {
                                island.push({ x, y });
                                grid[x][y] = 0;
                                local_area++;
                            }
                        }
                    }
                    area = max(area, local_area);
                }
            }
        }
        return area;
    }
    //��һ�ֵݹ�д�� �߽������ж�������һ�����жϺϷ�
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int max_area = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    max_area = max(DFS(grid, i, j), max_area);
            }
        }

        return max_area;
    }
    //����������������������ĵݹ����
    int DFS(vector<vector<int>>& grid, int r, int c)
    {
        if (grid[r][c] == 0)
            return 0;
        grid[r][c] = 0;     //�������
        int x, y, area = 1;
        for (int i = 0; i < direction.size() - 1; i++)
        {
            x = r + direction[i];
            y = c + direction[i + 1];
            if (x >= 0 && x < grid.size() &&
                y >= 0 && y < grid[0].size())
                area += DFS(grid, x, y);
        }
        return area;
    }
    */
    //�ڶ��ֵݹ�д�� �߽������ж������ж��Ƿ�Խ�磬�Ϸ��ٽ�����һ��
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int max_area = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    max_area = max(DFS(grid, i, j), max_area);
            }
        }

        return max_area;
    }
    //����������������������ĵݹ����
    int DFS(vector<vector<int>>& grid, int r, int c)
    {
        if (r < 0 || r >= grid.size() ||
            c < 0 || c >= grid[0].size() || grid[r][c] == 0)
            return 0;
        grid[r][c] = 0;
        return 1 + DFS(grid, r + 1, c) + DFS(grid, r, c + 1) +
            DFS(grid, r - 1, c) + DFS(grid, r, c - 1);
    }
private:
    vector<int> direction{ -1, 0, 1, 0, -1 };
};

int main()
{
    int x = 0;
    auto y = x;
}