#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution 
{
public:
    int monotoneIncreasingDigits(int n) 
    {
        if (n < 10)
            return n;
        string num = to_string(n);
        int size = num.size();
        for (int i = size - 1; i > 0; i--)
        {
            if (num[i - 1] > num[i])
            {
                for (int j = size - 1; j >= i; j--)
                    num[j] = '9';
                num[i - 1] = num[i - 1] - 1;
            }
        }
        int ans = stoi(num);
        return ans;
    }
};

int main()
{
    int n = 1234;
    Solution S;
    int ans = S.monotoneIncreasingDigits(n);

    return 0;
}