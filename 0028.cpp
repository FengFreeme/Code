#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    // 用KMP算法
    int strStr(string haystack, string needle) 
    {
        if (needle.size() == 0)
            return 0;
        vector<int> next(needle.size(), 0);
        getNext(&next[0], needle);
        int j = -1;
        // i 从 0 开始遍历字符串
        for (int i = 0; i < haystack.size(); i++)
        {
            // 不匹配
            while (j >= 0 && haystack[i] != needle[j + 1])
                // j 寻找之前匹配的位置
                j = next[j];
            // 匹配下一个字符
            if (haystack[i] == needle[j + 1])
                j++;
            // 如果j指向了模式串t的末尾，那么就说明模式串t完全匹配文本串s里的某个子串了
            if (j == needle.size() - 1)
                return i - needle.size() + 1;
        }
        return -1;
    }
    // 获取next数组
    void getNext(int* next, const string& s)
    {
        // i指向后缀末尾，j指向前缀末尾
        // 前缀表要统一减一(其中一个操作，还有不减的)
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++)
        {
            // next[j]就是记录着j(包括j)之前的子串的相同前后缀的长度。
            while (j >= 0 && s[i] != s[j + 1])
                // 向前回退
                j = next[j];
                // 那么就同时向后移动i 和j 说明找到了相同的前后缀
                // 同时还要将j(前缀的长度)赋给next[i], 因为next[i]要记录相同前后缀的长度。
            if (s[i] == s[j + 1])
                j++;
            // 将j（前缀长度）赋给next[i]
            next[i] = j;
        }
    }
};