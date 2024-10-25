#include <iostream>
#include <vector>
#include <list>

using namespace std;

// 搜集路径
vector<vector<int>> ans;
// 1 节点到终点的路经
vector<int> path;
/*
// 邻接矩阵
// 1. 确定参数和返回参数
void DFS(const vector<vector<int>> graph, int x, int n)
{
	// 2. 确定终止条件
	// 当遍历的节点 x 到达节点 n
	if (x == n)
	{
		ans.push_back(path);
		return;
	}
	// 3. 处理目前搜索节点出发的路径
	// 遍历节点 x 链接的节点
	for (int i = 1; i <= n; i++)
	{
		if (graph[x][i] == 1)
		{
			path.push_back(i);
			DFS(graph, i, n);
			path.pop_back();		// 回溯
		}
	}
}
*/
// 邻接表
// 1. 确定参数和返回参数
void DFS(vector<list<int>> graph, int x, int n)
{
	// 2. 确定终止条件
	if (x == n)
	{
		ans.push_back(path);
		return;
	}
	// 3. 处理目前搜索节点的出发路径
	// 找到 x 指向的节点
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
	// 邻接矩阵
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

	while (m--)
	{
		cin >> s >> t;
		/// 使用邻接矩阵 表示无向图，1 表示 s 与 t是相连的
		graph[s][t] = 1;
	}
	path.push_back(1);
	// 搜索所有从 1 到 n 的路径
	DFS(graph, 1, n);
	*/
	// 邻接表
	vector<list<int>> graph(n + 1);
	while (m--)
	{
		cin >> s >> t;
		// 使用邻接表 表示 s -> t
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