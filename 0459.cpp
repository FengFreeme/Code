#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int size = s.size();
        if (size == 1)
            return false;
        int _size = size / 2;
        bool isRepeat = true;
        // len为重复的字符串长度（如果存在）
        for (int len = 1; len <= _size; len++)
        {
            int j = len;
            while (j < size)
            {
                if (s.substr(0, len) == s.substr(j, len))
                {
                    isRepeat = true;
                    j += len;
                }
                else
                {
                    isRepeat = false;
                    break;
                }
            }
            if (isRepeat)
                return true;
        }
        return false;
    }
    bool repeatedSubstringPattern(string s)
    {
        string t = s + s;
        // 掐头去尾
        t.erase(t.begin());
        t.erase(t.end() - 1);
        // std::string::npos 是 std::string 类的一个静态成员常量，它代表一个特殊的值，用于表示未找到任何匹配的位置
        if (t.find(s) != std::string::npos)
            return true;
        return false;
    }
    bool repeatedSubstringPattern(string s)
    {
        string t = s + s;
        // 掐头去尾
        t.erase(t.begin());
        t.erase(t.end() - 1);
        // s是模式串，t是文本串
        return KMP(s, t);
    }
    bool KMP(string s, string t)
    {
        vector<int> next = vector<int>(s.size(), 0);
        int j = -1;
        next[0] = j;
        GetNext(next, s);
        for (int i = 0; i < t.size(); i++)
        {
            while (j >= 0 && s[j + 1] != t[i])
                j = next[j];
            if (s[j + 1] == t[i])
                j++;
            if (j == s.size() - 1)
                return true;
        }
        return false;
    }
    void GetNext(vector<int> &next, string s)
    {
        int j = -1;
        for (int i = 1; i < s.size(); i++)
        {
            // j回退到和当前字符相同的位置
            while (j >= 0 && s[j + 1] != s[i])
                j = next[j];
            if (s[j + 1] == s[i])
                j++;
            // 将前缀长度赋值给Next
            next[i] = j;
        }
    }
};

int main()
{
    string s = "abcabcabcabc";

    Solution S;
    cout << S.repeatedSubstringPattern(s);

    return 0;
}