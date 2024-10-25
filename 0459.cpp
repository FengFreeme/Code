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
        // lenΪ�ظ����ַ������ȣ�������ڣ�
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
        // ��ͷȥβ
        t.erase(t.begin());
        t.erase(t.end() - 1);
        // std::string::npos �� std::string ���һ����̬��Ա������������һ�������ֵ�����ڱ�ʾδ�ҵ��κ�ƥ���λ��
        if (t.find(s) != std::string::npos)
            return true;
        return false;
    }
    bool repeatedSubstringPattern(string s)
    {
        string t = s + s;
        // ��ͷȥβ
        t.erase(t.begin());
        t.erase(t.end() - 1);
        // s��ģʽ����t���ı���
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
            // j���˵��͵�ǰ�ַ���ͬ��λ��
            while (j >= 0 && s[j + 1] != s[i])
                j = next[j];
            if (s[j + 1] == s[i])
                j++;
            // ��ǰ׺���ȸ�ֵ��Next
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