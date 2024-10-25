#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
    /*
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int k = strs.size();
        for (int a = 1; a <= k; a++)
        {
            auto [count0, count1] = count(strs[a - 1]);
            for (int i = m; i >= count0; i--)
            {
                for (int j = n; j >= count1; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - count0][j - count1] + 1);

                    cout << dp[i][j] << " ";
                }
                cout << endl;
            }
        }
        return dp[m][n];
    }
    */
    /*
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int s = strs.size();
        vector<vector<int>> dp(s + 1, vector<int>(m + n + 1, 0));
        for (int i = 1; i <= s; i++)
        {
            auto [count0, count1] = count(strs[i - 1]);
            for (int j = 1; j <= m + n; j++)
            {
                if (j < count0 + count1 || m < count0 || n < count1)
                    dp[i][j] = dp[i - 1][j];
                else if (j >= count0 + count1 && m >= count0 && n >= count1)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - count0 - count1] + 1);
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[s][m + n];
    }
    */
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int s = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int k = 1; k <= s; k++)
        {
            auto [count0, count1] = count(strs[k - 1]);
            for (int i = m; i >= count0; i--)
            {
                for (int j = n; j >= count1; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - count0][j - count1] + 1);
                }
            }
            /*for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << dp[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl << endl;*/
        }
        return dp[m][n];
    }
    pair<int, int> count(const string& s)
    {
        int count0 = s.length(), count1 = 0;
        for (const char& c : s)
        {
            if (c == '1')
            {
                count1++;
                count0--;
            }
        }
        return make_pair(count0, count1);
    }
};

int main()
{
    vector<string> strs = { "10", "0001", "111001", "1", "0" };
    int m = 5, n = 3;

    Solution S;
    S.findMaxForm(strs, m, n);

    return 0;
}

