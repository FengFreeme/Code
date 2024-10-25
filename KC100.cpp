#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int direction[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };

int ans = 0;
int counts = 0;
// 1. 确定参数和返回参数
void DFS(vector<vector<int>> grid, vector<vector<bool>>& visited, int x, int y)
{
	// 2. 单次递归处理
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + direction[i][0];
		int nexty = y + direction[i][1];
		if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
			continue;
		if (grid[nextx][nexty] == 1 && visited[nextx][nexty] == false)
		{
			counts++;
			visited[nextx][nexty] = true;
			DFS(grid, visited, nextx, nexty);
		}
	}
}

void BFS(vector<vector<int>> grid, vector<vector<bool>>& visited, queue<pair<int, int>>& que)
{
	
	while (!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextx = x + direction[i][0];
			int nexty = y + direction[i][1];
			if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
				continue;
			if (grid[nextx][nexty] == 1 && visited[nextx][nexty] == false)
			{
				counts++;
				visited[nextx][nexty] = true;
				que.push({ nextx, nexty });
			}
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

	vector<vector<bool>> visited(n, vector<bool>(m, false));
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			counts = 0;
			if (grid[i][j] == 1 && visited[i][j] == false)
			{
				visited[i][j] = true;
				counts++;
				DFS(grid, visited, i, j);
				ans = max(ans, counts);
			}
		}
	}
	*/
	queue<pair<int, int>> que;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == 1 && visited[i][j] == false)
			{
				visited[i][j] = true;
				counts = 1;
				que.push({ i, j });
				BFS(grid, visited, que);
				ans = max(ans, counts);
			}
		}
	}
	cout << ans << endl;
}