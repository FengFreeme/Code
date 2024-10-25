#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    void reverseString(vector<char>& s) 
    {
        int n = s.size();
        int low = 0, high = n - 1;
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
};