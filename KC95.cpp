#include <iostream>
#include <vector>
#include <climits>

using namespace std;
// Bellman_ford 判断负权回路
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph;
	int s, t, v;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> t >> v;
		graph.push_back({ s,t,v });
	}
	vector<int> dist(n + 1, INT_MAX);
	int start = 1;
	int end = n;
	dist[start] = 0;
	// 对所有边松弛 n - 1次
	for (int i = 1; i < n; i++)
	{
		for (vector<int> edge : graph)
		{
			int from = edge[0];
			int to = edge[1];
			int val = edge[2];
			if (dist[from] != INT_MAX && dist[from] + val < dist[to])
			{
				dist[to] = dist[from] + val;
			}
		}
	}
	for (vector<int> edge : graph)
	{
		int from = edge[0];
		int to = edge[1];
		int val = edge[2];
		if (dist[from] != INT_MAX && dist[from] + val < dist[to])
		{
			cout << "circle" << endl;
			return 0;
		}
	}
	if (dist[n] == INT_MAX)
		cout << "unconnected" << endl;
	else
		cout << dist[n] << endl;
}