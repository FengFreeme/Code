#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
    /*
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (const string& word : wordDict)
            {
                int len = word.length();
                if (i >= len && s.substr(i - len, len) == word)     //在这里i看成是遍历到的长度
                    dp[i] = dp[i] || dp[i - len];
            }
        }
        return dp[n];
    }
    */
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int m = wordDict.size(), n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i <= m; i++)
            {
                int len = wordDict[i - 1].size();
                string str = wordDict[i - 1];
                if (j >= len && str == s.substr(j - len, len))
                    dp[j] = dp[j - len] || dp[j];
                //cout << dp[j] << " ";
            }
            //cout << endl;
        }
        return dp[n];
    }
};

int main()
{
    string s = "leetcode";
    vector<string> wordDict = { "leet", "code" };
    Solution S;
    S.wordBreak(s, wordDict);

    return 0;
}