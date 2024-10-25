#include <iostream>
#include <vector>

using namespace std;

int n;
void init(vector<int>& father)
{
	for (int i = 1; i < father.size(); i++)
		father[i] = i;
}

int find(vector<int>& father, int u)
{
	if (u == father[u])
		return u;
	else
		return father[u] = find(father, father[u]);		// 路径压缩
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
// 代码随想录
// 再有向图里找到删除的那条边，使其变成树
void getRemoveEdge(vector<int>& father, vector<vector<int>>& edges)
{
	// 初始化并查集
	init(father);
	// 遍历所有的边
	for (int i = 0; i < n; i++)
	{
		// 构成有向环 是要删除的边
		if (isSame(father, edges[i][0], edges[i][1]))
		{
			cout << edges[i][0] << " " << edges[i][1] << endl;
			return;
		}
		else
		{
			join(father, edges[i][0], edges[i][1]);
		}
	}
}
// 删除一条边之后判断是不是树
bool isTreeAfterRemoveEdge(vector<int>& father, vector<vector<int>>& edges, int deleteEdge)
{
	// 初始化并查集
	init(father);
	for (int i = 0; i < n; i++)
	{
		if (i == deleteEdge)
			continue;
		// 构成有向环，所以不是树
		if (isSame(father, edges[i][0], edges[i][1]))
			return false;
		join(father, edges[i][0], edges[i][1]);
	}
	return true;
}
int main()
{
	cin >> n;
	int s, t;
	vector<vector<int>> edges;
	// 记录入度
	vector<int> inDegree(n + 1, 0);
	vector<int> father(n + 1, 0);

	vector<pair<int, int>> edge;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> t;
		inDegree[t]++;
		edges.push_back({ s, t });
	}
	// 记录入度为 2 的 边
	vector<int> vec;
	// 找入度为 2 所对应的边
	for (int i = n - 1; i >= 0; i--)
	{
		if (inDegree[edges[i][1]] == 2)
			vec.push_back(i);
	}
	// 情况一：如果我们找到入度为2的点，那么删一条指向该节点的边就行了
	// 情况二：只能删特定的一条边
	if (vec.size() > 0)
	{
		if(isTreeAfterRemoveEdge(father, edges, vec[0]))
			cout << edges[vec[0]][0] << " " << edges[vec[0]][1] << endl;
		else
		{
			cout << edges[vec[1]][0] << " " << edges[vec[1]][1] << endl;
		}
		return 0;
	}
	// 情况三：有向环
	getRemoveEdge(father, edges);

	return 0;
}