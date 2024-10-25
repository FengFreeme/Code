#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };		// 四个方向
// 深度优先遍历
// 1. 确定参数和返回参数
void DFS(vector<vector<int>> grid, vector<vector<bool>>& visited, int x, int y)
{
	// 递归处理
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + dir[i][0];
		int nexty = y + dir[i][1];
		if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
			continue;
		// 没有访问过且是陆地
		if (!visited[nextx][nexty] && grid[nextx][nexty] == 1)
		{
			visited[nextx][nexty] = true;
			DFS(grid, visited, nextx, nexty);
		}
	}
}
// 广度优先遍历
void BFS(vector<vector<int>> grid, vector<vector<bool>>& visited, int x, int y)
{
	queue<pair<int, int>> que;
	que.push({ x, y });
	visited[x][y] = true;
	while (!que.empty())
	{
		auto coordinate = que.front();
		que.pop();
		int curx = coordinate.first;
		int cury = coordinate.second;
		for (int i = 0; i < 4; i++)
		{
			int nextx = curx + dir[i][0];
			int nexty = cury + dir[i][1];
			if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
				continue;
			// 未访问过且是陆地
			if (!visited[nextx][nexty] && grid[nextx][nexty] == 1)
			{
				visited[nextx][nexty] = true;
				que.push({ nextx, nexty });
			}
		}
	}
}
int main()
{
	/*
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

	vector<vector<bool>> visited(n, vector<bool>(m, false));

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && grid[i][j] == 1)
			{
				visited[i][j] = true;
				ans++;
				// 将与该结点链接的陆地都标记true
				DFS(grid, visited, i, j);
			}
		}
	}
	cout << ans << endl;
	*/
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
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == 1 && !visited[i][j])
			{
				ans++;
				BFS(grid, visited, i, j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}