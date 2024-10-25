#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> bolan;
        int n = tokens.size();
        for (int i = 0; i < n; i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int b = bolan.top();
                bolan.pop();
                int a = bolan.top();
                bolan.pop();
                int c;
                switch (tokens[i][0])
                {
                case '+':
                    c = a + b;
                    break;
                case '-':
                    c = a - b;
                    break;
                case '*':
                    c = a * b;
                    break;
                case '/':
                    c = a / b;
                    break;
                }

                bolan.push(c);
            }
            else
            {
                int num = StringToInt(tokens[i]);
                bolan.push(num);
            }
        }
        int ans = bolan.top();
        bolan.pop();
        return ans;
    }
    int StringToInt(string s)
    {
        int ans = 0;
        int flag = 1;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];       
            if (c == '-')
            {
                flag = -1;
                continue;
            }
            int num = c - '0';
            ans = ans * 10 + num;
        }
        return flag*ans;
    }
};

int main()
{
    vector<string> tokens = { "3","-4","+" };
    Solution S;
    S.evalRPN(tokens);

    return 0;
}