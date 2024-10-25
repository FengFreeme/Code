#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    /*
    //����һ �����쳲�����������
    int climbStairs(int n) 
    {
        if (n <= 2)
            return n;
        vector<int> dp(n + 1);
        dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];      //dp[1] = 1, dp[2] = 2
        }
        return dp[n];
    }
    */
    /*
    //������ �����쳲����������� �Ż��ռ� ֻ�����������洢ֵ
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int a = 2, b = 1;
        int methods = 0;
        for (int i = 3; i <= n; i++)
        {
            methods = a + b;
            b = a;
            a = methods;
        }
        return methods;
    }
    */
    int climbStairs(int n) 
    {
        if (n == 0 || n == 1)
            return n;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        cout << dp[0] << " " << dp[1] << " ";
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
            cout << dp[i] << " ";
        }
        return dp[n];
    }
};

int main()
{
    int n = 3;
    Solution S;
    S.climbStairs(n);

    return 0;
}