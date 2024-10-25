#include <iostream>
#include <vector>

using namespace std;

int direction[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
		}
	}
	
	int ans = 0;
	/*
	// ��һ
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == 1)
			{
				for (int k = 0; k < 4; k++)
				{
					int x = i + direction[k][0];
					int y = j + direction[k][1];
					if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
					{
						ans++;
						continue;
					}
					if (grid[x][y] == 0)
						ans++;
				}
			}
		}
	}
	*/
	// ����
	// ½������
	int sum = 0;
	// ��������
	int cover = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == 1)
			{
				sum++;
				// ͳ���ϱ�����½��
				if (i - 1 >= 0 && grid[i - 1][j] == 1)
					cover++;
				// ͳ�������������
				if (j - 1 >= 0 && grid[i][j - 1] == 1)
					cover++;
				// Ϊʲôûͳ���±ߺ��ұ� ��Ϊ�����ظ�����
			}
		}
	}
	ans = 4 * sum - cover * 2;
	cout << ans << endl;
}