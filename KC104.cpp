/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int direction[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };

int counts;
int ans = 0;

void BFS(vector<vector<int>> grid, vector<vector<bool>> visited, int x, int y)
{
	queue<pair<int, int>> que;
	que.push({ x, y });
	visited[x][y] = true;
	counts++;
	while (!que.empty())
	{
		int curx = que.front().first;
		int cury = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextx = curx + direction[i][0];
			int nexty = cury + direction[i][1];
			if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
				continue;
			if (grid[nextx][nexty] == 1 && !visited[nextx][nexty])
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

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			counts = 0;
			if (grid[i][j] == 0)
			{
				grid[i][j] = 1;
				BFS(grid, visited, i, j);
				ans = max(ans, counts);
				grid[i][j] = 0;		// ����
			}
			else if (grid[i][j] == 1)
			{
				BFS(grid, visited, i, j);
				ans = max(ans, counts);
			}
		}
	}
	cout << ans << endl;
}
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int n, m;
int counts;

int direction[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };

void DFS(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int mark)
{
	// 2. ��ֹ���������ʹ��Ľڵ����������ˮ
	if (visited[x][y] || grid[x][y] == 0)
		return;
	visited[x][y] = true;
	grid[x][y] = mark;		// �Ǳ�ǩ
	counts++;
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + direction[i][0];
		int nexty = y + direction[i][1];
		if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
			continue;
		DFS(grid, visited, nextx, nexty, mark);
	}
}

int main()
{
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

	unordered_map<int, int> gridNum;
	// ��¼ÿ������ı��
	int mark = 2;
	// ����Ƿ�������ͼ����½��
	bool isAllGrid = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == 0)
				isAllGrid = false;
			if (!visited[i][j] && grid[i][j] == 1)
			{
				counts = 0;
				DFS(grid, visited, i, j, mark);
				gridNum[mark] = counts;
				mark++;			// ��¼��һ��������
			}
		}
	}
	if (isAllGrid)
	{
		cout << n * m << endl;
		return 0;
	}

	int ans = 0;
	// ��Ƿ��ʹ��ĵ���
	unordered_set<int> visitedGrid;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// ��¼���Ӻ�ĵ�������
			counts = 1;
			// ÿ��ʹ��ʱ���
			visitedGrid.clear();
			if (grid[i][j] == 0)
			{
				for(int k = 0; k < 4; k++)
				{
					int nextx = i + direction[k][0];
					int nexty = j + direction[k][1];
					if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
						continue;
					// ��ӹ��ĵ��첻�ظ����
					if(visitedGrid.count(grid[nextx][nexty]))
						continue;
					counts += gridNum[grid[nextx][nexty]];
					visitedGrid.insert(grid[nextx][nexty]);
						
				}
			}
			ans = max(ans, counts);
		}
	}
	cout << ans << endl;
}