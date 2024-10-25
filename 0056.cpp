#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if (intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> ans;
        vector<int> interval(2);
        interval[0] = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (end < intervals[i][0])
            {
                interval[1] = end;
                ans.push_back(interval);
                interval[0] = intervals[i][0];
                end = intervals[i][1];
            }
            else if (end >= intervals[i][0])
            {
                end = max(end, intervals[i][1]);
            }

            if (i == intervals.size() - 1)
            {
                interval[1] = end;
                ans.push_back(interval);
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> intervals = { {1, 4},{4, 5}};

    Solution S;
    vector<vector<int>> ans = S.merge(intervals);

    return 0;
}