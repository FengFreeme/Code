#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int solve1(vector<int> weights, vector<int> values, int N, int W)
	{
		vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				//背包容量j不够，不放物品
				if (j < weights[i - 1])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		return dp[N][W];
	}
	int solve2(vector<int> weights, vector<int> values, int N, int W)
	{
		vector<int> dp(W + 1, 0);
		for (int i = 1; i <= N; i++)
		{
			for (int j = W; j >= 1; j--)
			{
				if (j < weights[i - 1])
					dp[j] = dp[j];
				else
					dp[j] = dp[j - weights[i - 1]] + values[i - 1];
			}
			for (int j = 1; j <= W; j++)
				cout << dp[j] << " ";
			cout << endl;
		}
		return dp[W];
	}
};

int main()
{
	vector<int> weights = { 1, 3, 4 };
	vector<int> values = { 15, 20, 30 };

	Solution S;
	S.solve1(weights, values, 3, 4);
	S.solve2(weights, values, 3, 4);

	return 0;
}