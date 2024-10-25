#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int fib(int n) 
    {
        if (n == 0 || n == 1)
            return n;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        cout << dp[0] << " " << dp[1] << " ";

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
            cout << dp[i];
        }
        return dp[n];
    }
};

int main()
{
    int n = 2;
    Solution S;
    S.fib(n);

    return 0;
}