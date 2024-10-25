#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<string>> ans;
    vector<string> path;
    vector<vector<string>> partition(string s) 
    {
        computePalindrome(s);
        backtracking(s, 0);

        return ans;
    }
    /*
    // 1. 确定参数和返回参数（无法事先确定）
    void backtracking(string substr)
    {
        // 2. 确定终止条件
        if (substr.size() == 0)
        {
            ans.push_back(path);
            return;
        }
        // 3. 单次递归处理
        for (int i = 1; i <= substr.size(); i++)
        {
            string t(substr.begin(), substr.begin() + i);
            string k = t;
            reverse(k.begin(), k.end());
            if (t == k)
            {
                path.push_back(t);
                string l(substr.begin() + i, substr.end());
                backtracking(l);
                path.pop_back();
            }
        }
    }
    */
    vector<vector<bool>> isPalindrome;      // 放事先计算好的是否回文子串的结果
    // 代码随想录
    void backtracking(const string& s, int startIndex)
    {
        // 分割线后面已经没有字符串了
        if (startIndex >= s.size())
        {
            ans.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            if (isPalindrome[startIndex][i])
            {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            else
                continue;
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
    // 给定一个字符串s, 长度为n, 它成为回文字串的充分必要条件是s[0] == s[n-1]且s[1:n-2]是回文字串。
    void computePalindrome(const string& s)
    {
        isPalindrome.resize(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (j == i)
                    isPalindrome[i][j] = true;
                else if (j - i == 1)
                    isPalindrome[i][j] = (s[i] == s[j]);
                else
                    isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
            }
        }
    }
};

int main()
{
    string s = "aab";

    Solution S;
    S.partition(s);

    return 0;
}