#include <iostream>
#include <vector>
#include <list>

using namespace std;
// �������
void DFS(vector<list<int>> graph, vector<bool>& visited, int x)
{
	// 2. ��ֹ����
	for (int i : graph[x])  // ����x ָ��Ľڵ�
	{
		if (!visited[i])
		{
			visited[i] = true;
			DFS(graph, visited, i);
		}
	}
}
// ʹ���ڽӱ�
int main()
{
	int n, k, s, t;
	cin >> n >> k;
	vector<list<int>> graph(n + 1);
	while (k--)
	{
		cin >> s >> t;
		graph[s].push_back(t);
	}
	vector<bool> visited(n + 1, false);
	visited[1] = true;
	DFS(graph, visited, 1);
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			cout << -1 << endl;
			return 0;
		}
	}
	cout << 1 << endl;

	return 0;
}