#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int num = 0;
        int Index = s.size() - 1;
        // 孩子数量作为外部循环
        for (int i = g.size() - 1; i >= 0; i--)
        {
            // 饼干数量作为内部循环
            if (Index >= 0 && g[i] <= s[Index])
            {
                Index--;
                num++;
            }
        }
        return num;
    }
};

int main()
{
    vector<int> g = { 10,9,8,7 };
    vector<int> s = { 5,6,7,8 };
    Solution S;

    cout << S.findContentChildren(g, s) << endl;

    return 0;
}