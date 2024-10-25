#include <iostream>
#include <vector>

using namespace std;

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
		return father[u] = find(father, father[u]);
}

bool isSame(vector<int> father, int u, int v)
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
	int n, s, t;
	vector<pair<int, int>> edge;
	cin >> n;
	vector<int> father(n + 1, 0);
	init(father);
	for (int i = 0; i < n; i++)
	{
		cin >> s >> t;
		// 如果已经在同一个集合，再加入这条边，就会出现环
		if (isSame(father, s, t))
			edge.push_back({ s, t });
		else
			join(father, s, t);
	}
	cout << edge.back().first << " " << edge.back().second << endl;
}