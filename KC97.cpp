#include <iostream>
#include <vector>
#include <climits>

using namespace std;
// Floyd 核心思想 动态规划 Auther:KaiChen 
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, INT_MAX));
	int u, v, w;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		graph[u][v] = w;
		graph[v][u] = w;
	}
	for (int i = 1; i <= n; i++)
	{
		graph[i][i] = 0;
	}
	// 迭代更新最短路径长度
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX && graph[i][k] + graph[k][j] < graph[i][j])
				{
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
	int q;
	cin >> q;
	int start, end;
	vector<vector<int>> path;
	for (int i = 0; i < q; i++)
	{
		cin >> start >> end;
		path.push_back({ start, end });
	}
	for (int i = 0; i < q; i++)
	{
		if (graph[path[i][0]][path[i][1]] == INT_MAX)
			cout << -1 << endl;
		else
			cout << graph[path[i][0]][path[i][1]] << endl;
	}
}