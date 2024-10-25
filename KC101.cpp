#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int direction[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };
int counts;
int ans = 0;
bool isolate = false;
/*
// 自己 深度优先遍历
void DFS(vector<vector<int>> grid, vector<vector<bool>>& visited, int x, int y)
{
	// 递归处理
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + direction[i][0];
		int nexty = y + direction[i][1];
		if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
			continue;
		if(grid[nextx][nexty] == 1 && !visited[nextx][nexty])
		{
			if (nextx == 0 || nextx == grid.size() - 1 || nexty == 0 || nexty == grid[0].size() - 1)
				isolate = true;
			visited[nextx][nexty] = true;
			counts++;
			DFS(grid, visited, nextx, nexty);
		}
	}
}
*/
// 代码随想录 深度优先遍历
void DFS(vector<vector<int>>& grid, int x, int y)
{
	grid[x][y] = 0;
	ans++;
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + direction[i][0];
		int nexty = y + direction[i][1];
		if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
			continue;
		if (grid[nextx][nexty] == 0)
			continue;
		DFS(grid, nextx, nexty);
	}
}

void BFS(vector<vector<int>>& grid, int x, int y)
{
	queue<pair<int, int>> que;
	que.push({ x, y });
	grid[x][y] = 0;
	ans++;
	while (!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for(int i = 0; i < 4; i++)
		{
			int nextx = x + direction[i][0];
			int nexty = y + direction[i][1];
			if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
				continue;
			if (grid[nextx][nexty] == 0)
				continue;
			que.push({ nextx, nexty });
			grid[nextx][nexty] = 0;
			ans++;
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
		}
	}
	/*
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			isolate = false;
			counts = 1;
			if (grid[i][j] == 1 && !visited[i][j])
			{
				visited[i][j] = true;
				if (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1)
					isolate = true;
				
				DFS(grid, visited, i, j);
				if(!isolate)
					ans += counts;
			}
		}
	}
	*/
	/*
	// 从左侧边和右侧边向中间遍历
	for (int i = 0; i < n; i++)
	{
		if (grid[i][0] == 1)
			DFS(grid, i, 0);
		if (grid[i][m - 1] == 1)
			DFS(grid, i, m - 1);
	}
	// 从上侧边和下侧边向中间遍历
	for (int j = 0; j < m; j++)
	{
		if (grid[0][j] == 1)
			DFS(grid, 0, j);
		if (grid[n - 1][j] == 1)
			DFS(grid, n - 1, j);
	}
	ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == 1)
				DFS(grid, i, j);
		}
	}
	*/
	// 从左侧边和右侧边向中间遍历
	for (int i = 0; i < n; i++)
	{
		if (grid[i][0] == 1)
			BFS(grid, i, 0);
		if (grid[i][m - 1] == 1)
			BFS(grid, i, m - 1);
	}
	// 从上侧边和下侧边向中间遍历
	for (int j = 0; j < m; j++)
	{
		if (grid[0][j] == 1)
			BFS(grid, 0, j);
		if (grid[n - 1][j] == 1)
			BFS(grid, n - 1, j);
	}
	ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == 1)
				BFS(grid, i, j);
		}
	}
	cout << ans << endl;
}