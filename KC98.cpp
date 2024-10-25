#include <iostream>
#include <vector>
#include <list>

using namespace std;

// �Ѽ�·��
vector<vector<int>> ans;
// 1 �ڵ㵽�յ��·��
vector<int> path;
/*
// �ڽӾ���
// 1. ȷ�������ͷ��ز���
void DFS(const vector<vector<int>> graph, int x, int n)
{
	// 2. ȷ����ֹ����
	// �������Ľڵ� x ����ڵ� n
	if (x == n)
	{
		ans.push_back(path);
		return;
	}
	// 3. ����Ŀǰ�����ڵ������·��
	// �����ڵ� x ���ӵĽڵ�
	for (int i = 1; i <= n; i++)
	{
		if (graph[x][i] == 1)
		{
			path.push_back(i);
			DFS(graph, i, n);
			path.pop_back();		// ����
		}
	}
}
*/
// �ڽӱ�
// 1. ȷ�������ͷ��ز���
void DFS(vector<list<int>> graph, int x, int n)
{
	// 2. ȷ����ֹ����
	if (x == n)
	{
		ans.push_back(path);
		return;
	}
	// 3. ����Ŀǰ�����ڵ�ĳ���·��
	// �ҵ� x ָ��Ľڵ�
	for (int i : graph[x])
	{
		path.push_back(i);
		DFS(graph, i, n);
		path.pop_back();
	}
	return;
}

int main()
{
	int n, m, s, t;
	cin >> n >> m;
	/*
	// �ڽӾ���
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

	while (m--)
	{
		cin >> s >> t;
		/// ʹ���ڽӾ��� ��ʾ����ͼ��1 ��ʾ s �� t��������
		graph[s][t] = 1;
	}
	path.push_back(1);
	// �������д� 1 �� n ��·��
	DFS(graph, 1, n);
	*/
	// �ڽӱ�
	vector<list<int>> graph(n + 1);
	while (m--)
	{
		cin >> s >> t;
		// ʹ���ڽӱ� ��ʾ s -> t
		graph[s].push_back(t);
	}

	path.push_back(1);
	DFS(graph, 1, n);

	if (ans.size() == 0)
		cout << -1 << endl;
	for (vector<int> _path : ans)
	{
		for (int i = 0; i < _path.size() - 1; i++)
		{
			cout << _path[i] << " ";
		}
		cout << _path[_path.size() - 1] << endl;
	}

	return 0;
}