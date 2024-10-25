#include <iostream>
#include <vector>
#include <list>
#include <climits>

using namespace std;
/*
// auther: KaiChen Prim�㷨
int main()
{
	int v, e;
	cin >> v >> e;
	int v1, v2, val;
	vector<list<pair<int, int>>> graph(v + 1);
	for (int i = 0; i < e; i++)
	{
		cin >> v1 >> v2 >> val;
		graph[v1].push_back({ v2, val });
		graph[v2].push_back({ v1, val });
	}
	// �����ĳ�ʼ�ڵ�Ϊ 1
	int node = 1;
	// ��¼�Ѿ�����Ľڵ�����
	int count = 1;
	// ��¼��̾���
	int value = 0;
	vector<bool> visited(v + 1, false);
	visited[1] = true;
	// ��¼���뼯�ϵĽڵ�
	vector<int> visitnode;
	visitnode.push_back(1);
	while (count != v)
	{
		int min_value = INT_MAX;
		pair<int, int> temp;
		for(int i = 0; i < visitnode.size(); i++)
		{
			for (pair<int, int> j : graph[visitnode[i]])
			{
				// �ý���Ѿ����ʹ�������
				if (visited[j.first])
					continue;
				// ��¼���������Ľڵ�
				if (j.second < min_value)
				{
					temp = j;
					min_value = j.second;
				}
			}
		}
		// ��¼���뼯�ϵĽڵ�
		visitnode.push_back(temp.first);
		// ��Ƿ��ʹ��Ľڵ�
		visited[temp.first] = true;
		count++;
		value += temp.second;
	}
	cout << value << endl;

	return 0;
}
*/
/*
// Auther: Carl. Prim�㷨
int main()
{
	int v, e;
	int x, y, k;
	cin >> v >> e;
	// �ڽӾ���
	vector<vector<int>> graph(v + 1, vector<int>(v + 1, 10001));
	while (e--)
	{
		cin >> x >> y >> k;
		graph[x][y] = k;
		graph[y][x] = k;
	}
	// ���нڵ㵽��С�������ľ���
	vector<int> minDist(v + 1, 10001);

	// ����ڵ��Ƿ�������
	vector<bool> isInTree(v + 1, false);

	// ����ֻ��Ҫѭ�� n-1�Σ����� n - 1���ߣ��Ϳ��԰�n���ڵ��ͼ����һ��
	for (int i = 1; i <= v; i++)
	{
		// 1. prim����������һ����ѡ��������������ڵ�
		// ��һ�μ�����ǽڵ� 1 
		int cur = -1;
		int minVal = INT_MAX;
		for (int j = 1; j <= v; j++)
		{
			//  ѡȡ��С�������ڵ��������
			//  (1) ������С��������
			//  (2) ������С����������Ľڵ�
			if (!isInTree[j] && minDist[j] < minVal)
			{
				minVal = minDist[j];
				cur = j;
			}
		}
		// 2. prim���������ڶ���������ڵ㣨cur������������
		isInTree[cur] = true;

		// 3. prim�������������������·��������ڵ㵽�������ľ��루������minDist���飩
		// cur�ڵ����֮�� ��С�������������µĽڵ㣬��ô���нڵ㵽 ��С�������ľ��루��minDist���飩��Ҫ����һ��
		// ����cur�ڵ����¼��뵽��С����������ôֻ��Ҫ������ cur ������ ���������ڵ� �ľ��� �Ƿ�� ԭ�� ���������ڵ㵽�������ڵ�ľ����С����
		for (int j = 1; j <= v; j++)
		{
			// ���µ�������
			// (1) �ڵ��� ����������Ľڵ�
			// (2) ��cur������ĳ�ڵ��Ȩֵ �� ��ĳ�ڵ������С�������ľ���С
			if (!isInTree[j] && graph[cur][j] < minDist[j])
			{
				minDist[j] = graph[cur][j];
			}
		}
	}
	int ans = 0;
	for (int i = 2; i <= v; i++)
	{
		ans += minDist[i];
	}
	cout << ans << endl;
}
*/
// Auther: KaiChen Kruskal�㷨
void init(vector<int>& father)
{
	for (int i = 1; i < father.size(); i++)
	{
		father[i] = i;
	}
}

int find(vector<int>& father, int u)
{
	if (u == father[u])
		return u;
	else
		return father[u] = find(father, father[u]);
}

bool isSame(vector<int>& father, int u, int v)
{
	u = find(father, u);
	v = find(father, v);
	return u == v;
}

void join(vector<int>& father, int u, int v)
{
	u = find(father, u);
	v = find(father, v);
	if (u == v)
		return;
	else
		father[v] = u;
}

int main()
{
	int v, e;
	cin >> v >> e;
	vector<vector<int>> graph(v + 1, vector<int>(v + 1, 0));
	// vector<list<pair<int, int>>> graph(v + 1);
	int v1, v2, val;
	for (int i = 0; i < e; i++)
	{
		cin >> v1 >> v2 >> val;
		graph[v1][v2] = val;
		graph[v2][v1] = val;
	}
	vector<int> father(v + 1, 0);
	init(father);
	// ��¼�����˼�����
	int count = 0;
	// ��¼��̾���
	int ans = 0;
	while (count != v - 1)
	{
		int m, n;
		int min_value = INT_MAX;
		for (int i = 1; i <= v; i++)
		{
			for (int j = i + 1; j <= v; j++)
			{
				if (graph[i][j] != 0 && graph[i][j] < min_value && !isSame(father, i, j))
				{
					min_value = graph[i][j];
					m = i;
					n = j;
				}
			}
		}
		join(father, m, n);
		ans += graph[m][n];
		graph[m][n] = 0;
		count++;
	}
	cout << ans << endl;
}