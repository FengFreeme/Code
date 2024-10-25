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
		return father[u] = find(father, father[u]);		// ·��ѹ��
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
// ��������¼
// ������ͼ���ҵ�ɾ���������ߣ�ʹ������
void getRemoveEdge(vector<int>& father, vector<vector<int>>& edges)
{
	// ��ʼ�����鼯
	init(father);
	// �������еı�
	for (int i = 0; i < n; i++)
	{
		// �������� ��Ҫɾ���ı�
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
// ɾ��һ����֮���ж��ǲ�����
bool isTreeAfterRemoveEdge(vector<int>& father, vector<vector<int>>& edges, int deleteEdge)
{
	// ��ʼ�����鼯
	init(father);
	for (int i = 0; i < n; i++)
	{
		if (i == deleteEdge)
			continue;
		// �������򻷣����Բ�����
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
	// ��¼���
	vector<int> inDegree(n + 1, 0);
	vector<int> father(n + 1, 0);

	vector<pair<int, int>> edge;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> t;
		inDegree[t]++;
		edges.push_back({ s, t });
	}
	// ��¼���Ϊ 2 �� ��
	vector<int> vec;
	// �����Ϊ 2 ����Ӧ�ı�
	for (int i = n - 1; i >= 0; i--)
	{
		if (inDegree[edges[i][1]] == 2)
			vec.push_back(i);
	}
	// ���һ����������ҵ����Ϊ2�ĵ㣬��ôɾһ��ָ��ýڵ�ı߾�����
	// �������ֻ��ɾ�ض���һ����
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
	// �����������
	getRemoveEdge(father, edges);

	return 0;
}