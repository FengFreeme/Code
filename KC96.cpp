#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph;
	int s, t, v;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> t >> v;
		graph.push_back({ s, t, v });
	}
	int src, dst, k;
	cin >> src >> dst >> k;
	vector<int> dist(n + 1, INT_MAX);
	vector<int> _dist(n + 1);
	dist[src] = 0;
	// �ɳ���� k + 1
	// ��㾭�������� k + 1 ���ߵ����յ����̾���
	for (int i = 1; i <= k + 1; i++)
	{
		_dist = dist;
		for (vector<int> edge : graph)
		{
			int from = edge[0];
			int to = edge[1];
			int val = edge[2];
			if (_dist[from] != INT_MAX && _dist[from] + val < dist[to])
				dist[to] = _dist[from] + val;
		}
	}
	if (dist[dst] == INT_MAX)
		cout << "unreachable" << endl;
	else
		cout << dist[dst] << endl;
}