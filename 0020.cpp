#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> braces;
        int n = s.size();
        if (n % 2 == 1)
            return false;
        braces.push(s[0]);
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[')
                braces.push(s[i]);
            else 
            {
                if (!braces.empty())
                {
                    char c = braces.top();
                    switch (s[i])
                    {
                    case '}':
                        if (c == '{')
                            braces.pop();
                        else
                            return false;
                        break;
                    case ')':
                        if (c == '(')
                            braces.pop();
                        else
                            return false;
                        break;
                    case ']':
                        if (c == '[')
                            braces.pop();
                        else
                            return false;
                        break;
                    }
                }
                else
                    return false;
            }
        }
        if (braces.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    string s = "(])";
    Solution S;
    S.isValid(s);

    return 0;
}