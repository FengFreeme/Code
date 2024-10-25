#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
using namespace std;
/*
// Dijkstra���ذ�
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
	// path[i]��ʾ��Դ�㵽���� i ֮�����·����ǰ���ڵ�
	vector<int> path(n + 1);
	// ��ʼ��dist��path
	for (int i = 2; i <= n; i++)
	{
		dist[i] = graph[1][i];
		path[i] = 1;
	}
	// ����Ƿ���뼯��
	vector<bool> visited(n + 1, false);
	
	visited[1] = true;
	for (int i = 2; i <= n; i++)
	{
		// 1. ѡ��ǰdist��С��·������Ӧ�Ķ��㣬����������뼯�ϣ�visited[i] = true��
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
		// 2. ����dist
		for (int i = 2; i <= n; i++)
		{
			if (visited[i] == false && graph[u][i] != INT_MAX && dist[u] + graph[u][i] < dist[i])
			{
				dist[i] = dist[u] + graph[u][i];
				// ����ǰ���ڵ�
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
// Dijkstra���Ż���
struct Edge
{
	// �ڽӶ���
	int to;
	// �ߵ�Ȩ��
	int val;

	Edge(int t, int u) :to(t), val(u) {};
};
// С����
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

	// ��¼Դ�㵽������������·��
	vector<int> dist(n + 1, INT_MAX);
	// ��¼�����Ƿ񱻼��뼯��
	vector<bool> visited(n + 1, false);
	// priority_queue<int> ��Ĭ�ϵĴ����ʵ�֣�top()�ǵ�ǰ���ȶ��е����ֵ
	// ���ȶ����д�� pair<�ڵ㣬Դ�㵽�ýڵ��Ȩֵ> ����С����
	// priority_queue<Type, Container, Functional> Type �����������ͣ�Container ������������
	priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pq;

	// ��ʼ������
	pq.push({ start, 0 });
	dist[1] = 0;
	while (!pq.empty())
	{
		// 1. ѡ��Ȩֵ��С����Ӧ������뼯��
		pair<int, int> cur = pq.top();
		pq.pop();

		// 2. ���뼯��
		visited[cur.first] = true;

		// 3. ����dist����
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