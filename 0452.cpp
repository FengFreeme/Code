#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
bool compare(vector<int> a, vector<int> b)
{
    if(a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}
*/
bool compare(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

class Solution 
{
public:
    /*
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        int size = points.size();
        sort(points.begin(), points.end(), compare);

        int arrow = points[0][1];
        int count = 1;
        for (int i = 1; i < size; i++)
        {
            if (points[i][0] > arrow)
            {
                arrow = points[i][1];
                count++;
            }
        }
        return count;
    }
    */
    int findMinArrowShots(vector<vector<int>>& points)
    {
        sort(points.begin(), points.end(), compare);
        int ans = 1;
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > points[i - 1][1])
                ans++;
            // 气球i和气球i-1挨着
            else
            {
                // 更新重叠气球最小有边界
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> points = { {3, 9},{7, 12},{3, 8},{6, 8},{9, 10},{2, 9},{0, 9},{3, 9},{0, 6},{2, 8} };

    Solution S;
    S.findMinArrowShots(points);

    return 0;
}