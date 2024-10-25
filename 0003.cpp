#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s == "")
            return 0;
        int len = s.size();
        int max = 1;
        for (int i = 0; i < len; i++)
        {
            unordered_map<char, int> hashtable;
            hashtable[s[i]] = i;        //���ַ��洢����ϣ����
            int sublen = 1;
            for (int j = i + 1; j < len; j++)
            {
                if (hashtable.find(s[j]) == hashtable.end())     //�ж�û���ظ�   
                {
                    sublen++;
                    hashtable[s[j]] = j;
                }
                else
                    break;
            }
            if (sublen > max)
                max = sublen;
        }
        return max;
    }
};
*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> hashtable;
        int r = -1, max = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i > 0)
                hashtable.erase(s[i - 1]);
            while (r + 1 < s.size() && hashtable.count(s[r + 1]) == 0)      //�ж��Ƿ��ظ�
            {
                hashtable.insert(s[r + 1]);
                r++;
            }
            if (r - i + 1 > max)
                max = r - i + 1;
        }
        return max;
    }
};
int main()
{
    string s = "aaaaa";
    Solution S;
    cout << S.lengthOfLongestSubstring(s) << endl;

    return 0;
}