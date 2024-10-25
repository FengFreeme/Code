#include <iostream>
#include <stack>
#include <iostream>

using namespace std;

class Solution 
{
public:
    string removeDuplicates(string s) 
    {
        stack<char> alpha;
        int n = s.size();
        alpha.push(s[0]);
        for (int i = 1; i < n; i++)
        {
            if (!alpha.empty())
            {
                char c = alpha.top();
                if (c == s[i])
                    alpha.pop();
                else
                    alpha.push(s[i]);
            }
            else
                alpha.push(s[i]);
        }
        int m = alpha.size();
        s.resize(m);
        int i = m - 1;
        while (!alpha.empty())
        {
            s[i] = alpha.top();
            alpha.pop();
            i--;
        }
        return s;
    }
    // ×Ö·û´®×÷ÎªÕ»
    string removeDuplicates(string s)
    {
        string result;
        for (char c : s)
        {
            if (result.empty() || result.back() != c)
                result.push_back(c);
            else
                result.pop_back();
        }
        return result;
    }
};

int main()
{
    string s = "abbaca";
    Solution S;
    S.removeDuplicates(s);

    return 0;
}