#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}
class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        // 记录非交叉区间的个数
        int ans = 1;
        sort(intervals.begin(), intervals.end(), compare);
        // 记录区间分割点
        int end = intervals[0][1];
        for (int i = 0; i < intervals.size(); i++)
        {
            // 找到下一个不重叠的区间更新end
            if (end <= intervals[i][0])
            {
                end = intervals[i][1];
                ans++;
            }
        }
        return intervals.size() - ans;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 100}, {11, 22}, {1, 11}, {2, 12}};
    Solution S;
    cout << S.eraseOverlapIntervals(intervals) << endl;

    return 0;
}