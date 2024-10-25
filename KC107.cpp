#include <iostream>
#include <vector>

using namespace std;

void init(vector<int>& father)
{
	for (int i = 0; i < father.size(); i++)
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
// 将v->u这条边加入并查集
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
	int n, m;
	cin >> n >> m;
	vector<int> father = vector<int>(n + 1, 0);
	init(father);
	int s, t;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> t;
		join(father, s, t);
	}
	cin >> s >> t;
	bool ans = isSame(father, s, t);
	if (ans)
		cout << 1 << endl;
	else
		cout << 0 << endl;
}