#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    bool isHappy(int n) 
    {
        int sum;
        unordered_set<int> uset;
        while (true)
        {
            sum = SquareSum(n);
            if (sum == 1)
                return true;
            // ’“µΩ£¨º¥÷ÿ∏¥
            if (uset.find(sum) != uset.end())
                return false;
            else
                uset.insert(sum);
            n = sum;
        }
    }
    int SquareSum(int n)
    {
        int sum = 0;
        while (n != 0)
        {
            int a = n % 10;
            sum += pow(a, 2);
            n = n / 10;
        }
        return sum;
    }
};