#include <iostream>
#include <vector>

using namespace std;

int direction[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };

void DFS(vector<vector<int>>& grid, int x, int y)
{
	grid[x][y] = 0;
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
	vector<vector<int>> _grid(grid);
	// вСср
	for (int i = 0; i < n; i++)
	{
		if (_grid[i][0] == 1)
			DFS(_grid, i, 0);
		if (_grid[i][m - 1])
			DFS(_grid, i, m - 1);
	}
	// иооб
	for (int j = 0; j < m; j++)
	{
		if (_grid[0][j] == 1)
			DFS(_grid, 0, j);
		if (_grid[n - 1][j] == 1)
			DFS(_grid, n - 1, j);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (_grid[i][j] == 1)
				grid[i][j] = 0;
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

}