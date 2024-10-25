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
        for (int i = 2; i <= n; i++)     //�ⲿ����
        {
            dp[i] = i;      //����������Ϊi
            for (int j = 2; j <= h; j++)
            {
                if (i % j == 0)
                {
                    //���i�ܹ���j�������Ǿ��൱�����쵽j���ȵ���С�������� + �ɳ���j�õ�i����Ҫ�Ĵ���
                    dp[i] = dp[j] + dp[i / j];      //�ɳ���j�õ�i����Ҫ�Ĵ������൱�ڰ�һ������Ϊ1��A��չ������Ϊi/j�Ĳ�������
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
            dp[i] = i;      //һ���������Ҫ�����Ĳ�������
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