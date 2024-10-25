#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
using namespace std;
/*
// Dijkstra朴素版
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, INT_MAX));
	int s, e, v;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e >> v;
		graph[s][e] = v;
	}
	vector<int> dist(n + 1, INT_MAX);
	// path[i]表示从源点到顶点 i 之间最短路径的前驱节点
	vector<int> path(n + 1);
	// 初始化dist和path
	for (int i = 2; i <= n; i++)
	{
		dist[i] = graph[1][i];
		path[i] = 1;
	}
	// 标记是否加入集合
	vector<bool> visited(n + 1, false);
	
	visited[1] = true;
	for (int i = 2; i <= n; i++)
	{
		// 1. 选择当前dist最小的路径和相应的顶点，并将顶点加入集合（visited[i] = true）
		int min_value = INT_MAX;
		int u;
		
		for (int i = 2; i <= n; i++)
		{
			if (visited[i] == false && dist[i] < min_value)
			{
				min_value = dist[i];
				u = i;
			}
		}
		visited[u] = true;
		// 2. 更新dist
		for (int i = 2; i <= n; i++)
		{
			if (visited[i] == false && graph[u][i] != INT_MAX && dist[u] + graph[u][i] < dist[i])
			{
				dist[i] = dist[u] + graph[u][i];
				// 更新前驱节点
				path[i] = u;
			}
		}
	}
	if (dist[n] == INT_MAX)
		cout << -1 << endl;
	else
		cout << dist[n] << endl;
}
*/
// Dijkstra堆优化版
struct Edge
{
	// 邻接顶点
	int to;
	// 边的权重
	int val;

	Edge(int t, int u) :to(t), val(u) {};
};
// 小顶堆
class mycomparison
{
public:
	bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
	{
		return lhs.second > rhs.second;
	}
};

int main()
{
	int m, n, p1, p2, val;
	cin >> n >> m;

	vector<list<Edge>> graph(n + 1);
	for (int i = 0; i < m; i++)
	{
		cin >> p1 >> p2 >> val;
		Edge edge(p2, val);
		graph[p1].push_back(edge);
	}

	int start = 1;
	int end = n;

	// 记录源点到其他顶点的最短路径
	vector<int> dist(n + 1, INT_MAX);
	// 记录顶点是否被加入集合
	vector<bool> visited(n + 1, false);
	// priority_queue<int> 是默认的大根堆实现，top()是当前优先队列的最大值
	// 优先队列中存放 pair<节点，源点到该节点的权值> 构造小顶堆
	// priority_queue<Type, Container, Functional> Type 就是数据类型，Container 就是容器类型
	priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pq;

	// 初始化队列
	pq.push({ start, 0 });
	dist[1] = 0;
	while (!pq.empty())
	{
		// 1. 选择权值最小的相应顶点加入集合
		pair<int, int> cur = pq.top();
		pq.pop();

		// 2. 加入集合
		visited[cur.first] = true;

		// 3. 更新dist数组
		for (Edge edge :graph[cur.first])
		{
			if (visited[edge.to] == false && dist[cur.first] + edge.val < dist[edge.to])
			{
				dist[edge.to] = dist[cur.first] + edge.val;
				pq.push({ edge.to, dist[edge.to] });
			}
		}
	}
	if (dist[n] == INT_MAX)
		cout << -1 << endl;
	else
		cout << dist[n] << endl;
}