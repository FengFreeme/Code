#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
    vector<string> ans;
    string path;
    vector<string> restoreIpAddresses(string s) 
    {
        if (s.size() < 4 || s.size() > 12)
            return ans;
        backtracking(s, s);

        return ans;
    }
    
    // 1. ȷ�������ͷ��ز���
    void backtracking(string s, string substr)
    {
        // 2. ȷ����ֹ����
        if (s.size() + 3 == path.size() && substr.size() == 0)
        {
            ans.push_back(path);
            return;
        }

        // 3. ���εݹ鴦��
        for (int i = 1; i <= substr.size(); i++)
        {
            // �� substr �����ν�ȡ���ַ��������ж�
            string t(substr.begin(), substr.begin() + i);
            int num = stoi(t);
            if (0 <= num && num <= 255 && (t[0] != '0' || (t[0] == '0' && t.size() == 1)))
            {
                string k(substr.begin() + i, substr.end());
                int len = path.size();
                if (path.size() == 0)
                    path = path + to_string(num);
                else
                    path = path + "." + to_string(num);
                backtracking(s, k);
                path.resize(len);
            }
            else
                break;
        }
    }
    
    /*
    // startIndex: ��������ʼλ�ã�pointNum:��Ӷ��������
    void backtracking(string& s, int startIndex, int pointNum)
    {
        if (pointNum == 3)
        {
            if (isValid(s, startIndex, s.size() - 1))
                ans.push_back(s);
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            if (isValid(s, startIndex, i))
            {
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                backtracking(s, i + 2, pointNum);
                pointNum--;
                s.erase(s.begin() + i + 1);
            }
            else
                break;
        }
    }
    bool isValid(const string& s, int start, int end)
    {
        if (start > end)
            return false;
        if (s[start] == '0' && start != end)        // ��ͷΪ0�����ֲ��Ϸ�
            return 0;

        int num = 0;
        for (int i = start; i <= end; i++)
        {
            if (s[i] > '9' || s[i] < '0')
                return false;
            num = num * 10 + s[i] - '0';
            if (num > 255)
                return false;
        }
        return true;
    }
    */
};

int main()
{
    string s = "101023";

    Solution S;
    S.restoreIpAddresses(s);

    return 0;
}