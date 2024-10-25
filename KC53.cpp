#include <iostream>
#include <vector>
#include <list>
#include <climits>

using namespace std;
/*
// auther: KaiChen Prim算法
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
	// 设加入的初始节点为 1
	int node = 1;
	// 记录已经加入的节点数量
	int count = 1;
	// 记录最短距离
	int value = 0;
	vector<bool> visited(v + 1, false);
	visited[1] = true;
	// 记录加入集合的节点
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
				// 该结点已经访问过，跳过
				if (visited[j.first])
					continue;
				// 记录符合条件的节点
				if (j.second < min_value)
				{
					temp = j;
					min_value = j.second;
				}
			}
		}
		// 记录加入集合的节点
		visitnode.push_back(temp.first);
		// 标记访问过的节点
		visited[temp.first] = true;
		count++;
		value += temp.second;
	}
	cout << value << endl;

	return 0;
}
*/
/*
// Auther: Carl. Prim算法
int main()
{
	int v, e;
	int x, y, k;
	cin >> v >> e;
	// 邻接矩阵
	vector<vector<int>> graph(v + 1, vector<int>(v + 1, 10001));
	while (e--)
	{
		cin >> x >> y >> k;
		graph[x][y] = k;
		graph[y][x] = k;
	}
	// 所有节点到最小生成树的距离
	vector<int> minDist(v + 1, 10001);

	// 这个节点是否在树里
	vector<bool> isInTree(v + 1, false);

	// 我们只需要循环 n-1次，建立 n - 1条边，就可以把n个节点的图连在一起
	for (int i = 1; i <= v; i++)
	{
		// 1. prim三部曲，第一步：选距离生成树最近节点
		// 第一次加入的是节点 1 
		int cur = -1;
		int minVal = INT_MAX;
		for (int j = 1; j <= v; j++)
		{
			//  选取最小生成树节点的条件：
			//  (1) 不在最小生成树里
			//  (2) 距离最小生成树最近的节点
			if (!isInTree[j] && minDist[j] < minVal)
			{
				minVal = minDist[j];
				cur = j;
			}
		}
		// 2. prim三部曲，第二步：最近节点（cur）加入生成树
		isInTree[cur] = true;

		// 3. prim三部曲，第三步：更新非生成树节点到生成树的距离（即更新minDist数组）
		// cur节点加入之后， 最小生成树加入了新的节点，那么所有节点到 最小生成树的距离（即minDist数组）需要更新一下
		// 由于cur节点是新加入到最小生成树，那么只需要关心与 cur 相连的 非生成树节点 的距离 是否比 原来 非生成树节点到生成树节点的距离更小了呢
		for (int j = 1; j <= v; j++)
		{
			// 更新的条件：
			// (1) 节点是 非生成树里的节点
			// (2) 与cur相连的某节点的权值 比 该某节点距离最小生成树的距离小
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
// Auther: KaiChen Kruskal算法
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
	// 记录加入了几条边
	int count = 0;
	// 记录最短距离
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