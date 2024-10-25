#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
    string reverseStr(string s, int k)
    {
        int n = s.size();
        if (n < k)
        {
            reverseString(s, 0, n - 1);
            return s;
        }
        int count = 0;
        int low, high;
        for (int i = 0; i < n; i++)
        {
            if (count == 0)
                low = i;
            count++;
            if (count == k)
            {
                high = i;
            }
            if (count == 2 * k)
            {
                reverseString(s, low, high);
                count = 0;
            }
        }
        if(count != 0 && count < k)
            reverseString(s, low, n - 1);
        else if(count != 0 && count < 2 * k)
            reverseString(s, low, high);
        return s;
    }
    void reverseString(string &s, int low, int high)
    {
        char c;
        while (low < high)
        {
            c = s[high];
            s[high] = s[low];
            s[low] = c;
            low++;
            high--;
        }
    }
    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.size(); i += (2 * k))
        {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size())
                reverse(s.begin() + i, s.begin() + i + k);
            else
                // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
                reverse(s.begin() + i, s.end());
        }
        return s;
    }
};

int main()
{
    string s = "abcdefg";
    int k = 8;

    Solution S;
    cout << S.reverseStr(s, k) << endl;

    return 0;
}