#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution 
{
public:
    int minSteps(int n) 
    {
        vector<int> dp(n + 1);
        int h = sqrt(n);
        for (int i = 2; i <= n; i++)     //外部背包
        {
            dp[i] = i;      //最多操作次数为i
            for (int j = 2; j <= h; j++)
            {
                if (i % j == 0)
                {
                    //如果i能够被j整除，那就相当于延伸到j长度的最小操作次数 + 由长度j得到i所需要的次数
                    dp[i] = dp[j] + dp[i / j];      //由长度j得到i所需要的次数，相当于把一个长度为1的A延展到长度为i/j的操作次数
                    cout << dp[i] << " ";
                    break;
                }
            }
            cout << dp[i] << " ";
        }
        return dp[n];
    }
    int minSteps(int n)
    {
        vector<int> dp(n + 1);
        int h = sqrt(n);
        for (int i = 2; i <= n; i++)
        {
            dp[i] = i;      //一般而言所需要的最多的操作次数
            for (int j = 2; j <= h; j++)
            {
                if (i % j == 0)
                {
                    dp[i] = dp[j] + dp[i / j];
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    int n = 3;
    Solution S;
    S.minSteps(n);

    return 0;
}