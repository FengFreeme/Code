#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>

using namespace std;

// Bellman_ford 算法
int main()
{
	int n, m, p1, p2, val;
	cin >> n >> m;

	vector<vector<int>> graph;

	// 将所有边保存起来
	for (int i = 0; i < m; i++)
	{
		cin >> p1 >> p2 >> val;
		graph.push_back({ p1, p2, val });
	}

	int start = 1;
	int end = n;

	vector<int> dist(n + 1, INT_MAX);
	dist[start] = 0;
	// 对所有边松弛 n - 1 次
	for (int i = 1; i < n; i++)
	{
		// 每次松弛 对所有边松弛
		for (vector<int>& edge : graph)
		{
			int from = edge[0];
			int to = edge[1];
			int value = edge[2];
			// 松弛操作
			if (dist[from] != INT_MAX && dist[to] > dist[from] + value)
				dist[to] = dist[from] + value;
		}
	}
	// 不能到达终点
	if (dist[end] == INT_MAX)
		cout << "unconnected" << endl;
	else
		cout << dist[end] << endl;
}

/*
// Bellman_ford 队列优化算法 Auther: KaiChen  Improved：Carl.
struct Edge
{
	int to;
	int val;
	Edge(int v, int value) :to(v), val(value) {}
};
int main()
{
	int n, m;
	cin >> n >> m;
	// vector<vector<int>> graph;
	vector<list<Edge>> edges(n+1);
	int s, t, v;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> t >> v;
		edges[s].push_back(Edge(t, v));
	}
	int start = 1;
	int end = n;

	vector<int> dist(n + 1, INT_MAX);
	vector<bool> IsInQue(n + 1, false);
	dist[start] = 0;
	queue<int> que;
	que.push(start);
	IsInQue[start] = true;
	while (!que.empty())
	{
		int cur = que.front();
		que.pop();
		IsInQue[cur] = false;
		for (Edge edge : edges[cur])
		{
			if (dist[edge.to] > dist[cur] + edge.val)
			{
				dist[edge.to] = dist[cur] + edge.val;
				if(!IsInQue[edge.to])
				{
					que.push(edge.to);
					IsInQue[edge.to] = true;
				}
			}
		}
	}
	if (dist[n] == INT_MAX)
	{
		cout << "unconnected" << endl;
	}
	else
	{
		cout << dist[n] << endl;
	}
}
*/