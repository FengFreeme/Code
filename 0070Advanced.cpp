#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	//动态规划 + 完全背包 + 排列数
	int climbStairs(int n, int m)
	{
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		for (int j = 0; j <= n; j++)
		{
			for (int i = 1; i <= m; i++)
			{
				if (j >= i)
					dp[j] = dp[j] + dp[j - i];
				//cout << dp[j] << " ";
			}
			//cout << endl;
		}
		return dp[n];
	}
};

int main()
{
	int n = 3, m = 2;

	Solution S;
	S.climbStairs(n, m);

	return 0;
}