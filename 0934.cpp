#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//ͼ����Ŀ
class Solution 
{
public:
    int shortestBridge(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> points;
        bool flipped = false;
        //DFSѰ�ҵ�һ�������ĵ���
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
        //BFSѰ�ҵڶ�������
        int x, y;
        int level = 0;
        while (!points.empty())         //�ȷ������е��ڽӶ���
        {
            level++;
            int n_points = points.size();
            while (n_points--)
            {
                auto [r, c] = points.front();   //���ض����еĵ�һ��Ԫ��
                points.pop();       //ɾ�����е�һ��Ԫ��
                for (int k = 0; k < 4; k++)
                {
                    x = r + direction[k];
                    y = c + direction[k + 1];
                    if (x >= 0 && y >= 0 && x < m && y < n)
                    {
                        if (grid[x][y] == 2)        //�Ѿ����ʹ�������
                            continue;
                        if (grid[x][y] == 1)        //�ҵ�����һ������
                            return level;
                        points.push({ x, y });      //�ѽ�����Ҫ���ʵ��ڽӶ���Ž�ȥ
                        grid[x][y] = 2;             //����ѷ���
                    }
                }
            }
        }
        return 0;
    }
    //������ ������ȱ���
    void DFS(queue<pair<int, int>>& points, vector<vector<int>>& grid, int m, int n, int i, int j)
    {
        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 2)
            return;
        if (grid[i][j] == 0)    
        {
            points.push({ i, j });      //��¼��֪������ڽӶ���
            return;
        }
        grid[i][j] = 2;     //�����������ӵĵ�����
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