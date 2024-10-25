#include <iostream>
#include <queue>
#include <string>

using namespace std;

int moves[1001][1001];
int dir[8][2] = { -2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2 };
int b1, b2;

// F = G + H
// G = 从起点到该节点路径消耗
// H = 从该节点到终点的路径消耗
// g 代表从起始点到当前骑士位置的路径成本。
// h 代表从当前骑士位置到目标位置的启发式估计成本，这通常使用某种启发式函数计算得出，如曼哈顿距离。
// f 是 g 和 h 的总和，代表从起始点到目标位置经过当前骑士位置的估计总成本。
struct Knight
{
	int x, y;
	int g, h, f;
	// 重载运算符，从小到达排序
	bool operator < (const Knight& k) const {
		return k.f < f;
	}
};

priority_queue<Knight> que;
// 欧拉距离
int Heuristic(const Knight& k)
{
	// 不开根号 提高精度
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
			// 如果当前节点没有访问过，则访问，并标记路径长度
			if (!moves[next.x][next.y])
			{
				moves[next.x][next.y] = moves[cur.x][cur.y] + 1;

				// 计算F
				// 不开根号 提高精度 马走日，1 * 1 + 2 * 2 = 5
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
		// memset(moves, 0, sizeof(moves));这行代码的作用是将 moves 指向的内存块中的每个字节都设置为0
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