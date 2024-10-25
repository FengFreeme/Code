#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
	int m, n, s, t;
	cin >> n >> m;
	// ��¼���
	vector<int> inDegree(n, 0);
	// ��¼��ϵ
	unordered_map<int, vector<int>> umap;
	vector<int> ans;

	while (m--)
	{
		cin >> s >> t;
		inDegree[t]++;
		// ��¼ s ָ�� �Ķ���
		umap[s].push_back(t);
	}
	queue<int> que;
	for (int i = 0; i < n; i++)
	{
		if (inDegree[i] == 0)
			que.push(i);
	}
	while (!que.empty())
	{
		int cur = que.front();
		que.pop();
		ans.push_back(cur);
		// ��ȡָ��Ľڵ�
		vector<int> u = umap[cur];
		if (u.size() > 0)
		{
			for (int i = 0; i < u.size(); i++)
			{
				inDegree[u[i]]--;
				if (inDegree[u[i]] == 0)
					que.push(u[i]);
			}
		}
	}
	if (ans.size() == n)
	{
		for (int i = 0; i < n - 1; i++)
			cout << ans[i] << " ";
		cout << ans[n - 1];
	}
	else
		cout << -1 << endl;
}