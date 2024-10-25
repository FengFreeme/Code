#include <iostream>
#include <vector>

using namespace std;

int direction[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };

void DFS(vector<vector<int>> grid, vector<vector<bool>>& flow, int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + direction[i][0];
		int nexty = y + direction[i][1];
		if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
			continue;
		if (grid[nextx][nexty] >= grid[x][y] && flow[nextx][nexty] == false)
		{
			flow[nextx][nexty] = true;
			DFS(grid, flow, nextx, nexty);
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

	vector<vector<bool>> flow1(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
	{
		flow1[i][0] = true;
		DFS(grid, flow1, i, 0);
	}
	for (int j = 0; j < m; j++)
	{
		flow1[0][j] = true;
		DFS(grid, flow1, 0, j);
	}

	vector<vector<bool>> flow2(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
	{
		flow2[i][m - 1] = true;
		DFS(grid, flow2, i, m - 1);
	}
	for (int j = 0; j < m; j++)
	{
		flow2[n - 1][j] = true;
		DFS(grid, flow2, n - 1, j);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (flow1[i][j] && flow2[i][j])
				cout << i << " " << j << endl;
		}
	}
	return 0;
}