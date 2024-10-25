#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
    string minWindow(string s, string t) 
    {
        vector<int> chars(128, 0);
        vector<bool> flag(128, false);
        //统计字符
        for (int i = 0; i < t.size(); i++)
        {
            flag[t[i]] = true;
            chars[t[i]]++;
        }
        //滑动窗口
        int cnt = 0, l = 0, min_l = 0, min_size = s.size() + 1;
        for (int r = 0; r < s.size(); r++)
        {
            //是t里面的字符
            if (flag[s[r]])
            {
                if (--chars[s[r]] >= 0)     //判断是否还有字符
                    cnt++;
            }
            //若目前滑动窗口已经包含t全部字符，
            //则尝试将l右移，在不影响结果的情况下获得最短字符串
            while (cnt == t.size())
            {
                if (r - l + 1 < min_size)
                {
                    min_l = l;
                    min_size = r - l + 1;
                }
                if (flag[s[l]] && ++chars[s[l]] > 0)
                    cnt--;
                l++;
            }
        }
        return min_size > s.size() ? "" : s.substr(min_l, min_size);
    }
};