#include <iostream>
#include <cmath>
using namespace std;
/*
class Solution 
{
public:
    int mySqrt(int x) 
    {
        if (x == 0)
            return x;
        int l = 1, r = x, mid, sqrt;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            sqrt = x / mid;
            if (sqrt == mid)
                return sqrt;
            else if (sqrt > mid)
                l = mid + 1;
            else if(sqrt < mid)
                r = mid - 1;
        }
        return r;   //在二分查找过程中mid或r不断接近真实值
    }
};
*/
/*
//方法二
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return x;
        int ans = exp(0.5 * log(x));

        return (long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans;       //由于存在误差，所以答案也可能是ans+1
    }
};
*/
class Solution
{
public:
    int mySqrt(int c)
    {
        if (c == 0)
            return c;
        long x = c;
        while (x * x > c)
        {
            x = 0.5 * (x + c / x);
        }
        return x;
    }
};
int main()
{
    int x = 8;
    Solution S;
    cout << S.mySqrt(8);

    return 0;
}