#include <iostream>
#include <queue>
#include <string>

using namespace std;

int moves[1001][1001];
int dir[8][2] = { -2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2 };
int b1, b2;

// F = G + H
// G = ����㵽�ýڵ�·������
// H = �Ӹýڵ㵽�յ��·������
// g �������ʼ�㵽��ǰ��ʿλ�õ�·���ɱ���
// h ����ӵ�ǰ��ʿλ�õ�Ŀ��λ�õ�����ʽ���Ƴɱ�����ͨ��ʹ��ĳ������ʽ��������ó����������پ��롣
// f �� g �� h ���ܺͣ��������ʼ�㵽Ŀ��λ�þ�����ǰ��ʿλ�õĹ����ܳɱ���
struct Knight
{
	int x, y;
	int g, h, f;
	// �������������С��������
	bool operator < (const Knight& k) const {
		return k.f < f;
	}
};

priority_queue<Knight> que;
// ŷ������
int Heuristic(const Knight& k)
{
	// �������� ��߾���
	return (k.x - b1) * (k.x - b1) + (k.y - b2) * (k.y - b2);
}

void astart(const Knight& k)
{
	Knight cur, next;
	que.push(k);
	while (!que.empty())
	{
		cur = que.top();
		que.pop();
		if (cur.x == b1 && cur.y == b2)
			break;
		for (int i = 0; i < 8; i++)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			if (next.x < 1 || next.x > 1000 || next.y < 1 || next.y > 1000)
				continue;
			// �����ǰ�ڵ�û�з��ʹ�������ʣ������·������
			if (!moves[next.x][next.y])
			{
				moves[next.x][next.y] = moves[cur.x][cur.y] + 1;

				// ����F
				// �������� ��߾��� �����գ�1 * 1 + 2 * 2 = 5
				next.g = cur.g + 5;
				next.h = Heuristic(next);
				next.f = next.g + next.h;
				que.push(next);
			}
		}
	}
}

int main()
{
	int n, a1, a2;
	cin >> n;
	while (n--)
	{
		cin >> a1 >> a2 >> b1 >> b2;
		// memset(moves, 0, sizeof(moves));���д���������ǽ� moves ָ����ڴ���е�ÿ���ֽڶ�����Ϊ0
		memset(moves, 0, sizeof(moves));
		Knight start;
		start.x = a1;
		start.y = a2;
		start.g = 0;
		start.h = Heuristic(start);
		start.f = start.g + start.h;
		astart(start);
		while (!que.empty())
			que.pop();
		cout << moves[b1][b2] << endl;
	}
	return 0;
}