#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    // ��KMP�㷨
    int strStr(string haystack, string needle) 
    {
        if (needle.size() == 0)
            return 0;
        vector<int> next(needle.size(), 0);
        getNext(&next[0], needle);
        int j = -1;
        // i �� 0 ��ʼ�����ַ���
        for (int i = 0; i < haystack.size(); i++)
        {
            // ��ƥ��
            while (j >= 0 && haystack[i] != needle[j + 1])
                // j Ѱ��֮ǰƥ���λ��
                j = next[j];
            // ƥ����һ���ַ�
            if (haystack[i] == needle[j + 1])
                j++;
            // ���jָ����ģʽ��t��ĩβ����ô��˵��ģʽ��t��ȫƥ���ı���s���ĳ���Ӵ���
            if (j == needle.size() - 1)
                return i - needle.size() + 1;
        }
        return -1;
    }
    // ��ȡnext����
    void getNext(int* next, const string& s)
    {
        // iָ���׺ĩβ��jָ��ǰ׺ĩβ
        // ǰ׺��Ҫͳһ��һ(����һ�����������в�����)
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++)
        {
            // next[j]���Ǽ�¼��j(����j)֮ǰ���Ӵ�����ͬǰ��׺�ĳ��ȡ�
            while (j >= 0 && s[i] != s[j + 1])
                // ��ǰ����
                j = next[j];
                // ��ô��ͬʱ����ƶ�i ��j ˵���ҵ�����ͬ��ǰ��׺
                // ͬʱ��Ҫ��j(ǰ׺�ĳ���)����next[i], ��Ϊnext[i]Ҫ��¼��ͬǰ��׺�ĳ��ȡ�
            if (s[i] == s[j + 1])
                j++;
            // ��j��ǰ׺���ȣ�����next[i]
            next[i] = j;
        }
    }
};