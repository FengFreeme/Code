#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    string reverseWords1(string s) 
    {
        int size = s.size();

        string ans;
        // 双指针
        int s1 = size - 1, s2 = size - 1;

        bool FindStart = false;
        bool FindEnd = false;
        // 反转
        while (s1 >= 0 && s2 >= 0)
        {
            if (s[s1] == ' ' && !FindEnd)
            {
                s1--;
                continue;
            }
            else if(s[s1] != ' ' && !FindEnd)
            {
                FindEnd = true;
                s2 = s1;
            }
            if ((s2 - 1 == -1 || s[s2 - 1] == ' ') && FindEnd && !FindStart)
            {
                FindStart = true;
            }
            else if(FindEnd && !FindStart)
            {
                s2--;
                continue;
            }
            if (FindStart && FindEnd)
            {
                string temp;
                temp = s.substr(s2, s1 - s2 + 1);
                ans = ans + temp + " ";

                FindStart = false;
                FindEnd = false;
                s1 = s2 - 1;
            }
        }
        ans.pop_back();
        return ans;
    }
    string reverseWords2(string s)
    {
        RemoveExtraSpace(s);

        int size = s.size();
        int low, high;
        low = 0, high = size - 1;
        char c;
        while (low < high)
        {
            c = s[low];
            s[low] = s[high];
            s[high] = c;
            low++;
            high--;
        }
        // 双指针
        int s1 = 0, s2 = 0;

        bool FindStart = false;
        bool FindEnd = false;
        // 反转
        while (s1 < size && s2 < size)
        {
            if (s[s1] == ' ' && !FindStart)
            {
                s1++;
                continue;
            }
            else if (s[s1] != ' ' && !FindStart)
            {
                FindStart = true;
                s2 = s1;
            }
            if ((s[s2 + 1] == ' ' || s2 + 1 == size) && !FindEnd && FindStart)
            {
                FindEnd = true;
            }
            else if (!FindEnd && FindStart)
            {
                s2++;
                continue;
            }
            if (FindStart && FindEnd)
            {
                low = s1, high = s2;
                while (low < high)
                {
                    c = s[low];
                    s[low] = s[high];
                    s[high] = c;
                    low++;
                    high--;
                }
                FindStart = false;
                FindEnd = false;
                s1 = s2 + 1;
            }
        }
        return s;
    }
    void RemoveExtraSpace(string& s)
    {
        // 快慢指针
        int slow = 0;
        int size = s.size(), NewSize = size;
        for (int fast = 0; fast < size; fast++)
        {
            if (s[fast] != ' ' || (fast > 0 && s[fast] == ' ' && s[fast] != s[fast - 1]))
            {
                s[slow++] = s[fast];
            }
        }
        if (s[slow - 1] == ' ')
            slow--;
        s.resize(slow);
    }
    string reverseWords(string s)
    {
        // 首先要移除多余的空格，使用双指针原地修改字符串
        int len = s.size();
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < len; fastIndex++)
        {
            if (fastIndex == 0 && s[fastIndex] != ' ')
            {
                s[slowIndex] = s[fastIndex];
                slowIndex++;
            }
            if ((fastIndex > 0 && s[fastIndex] != ' ') || (fastIndex > 0 && s[fastIndex] == ' ' && s[fastIndex] != s[fastIndex - 1]))
            {
                s[slowIndex] = s[fastIndex];
                slowIndex++;
            }
        }
        if (s[slowIndex - 1] == ' ')
            slowIndex--;
        s.resize(slowIndex);
        // 开始反转字符串
        Reverse(s, 0, slowIndex - 1);
        int low = 0;
        for (int high = 0; high < slowIndex; high++)
        {
            if (s[high + 1] == ' ' || high + 1 >= slowIndex)
            {
                Reverse(s, low, high);
                if (high + 1 < slowIndex)
                    low = high + 2;
            }
        }
        return s;
    }
    void Reverse(string& s, int low, int high)
    {
        while (low < high)
        {
            swap(s[low], s[high]);
            low++;
            high--;
        }
    }
};

int main()
{
    string s = "the sky is blue";
    Solution S;
    cout << S.reverseWords(s);

    return 0;
}