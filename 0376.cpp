#include <iostream>
#include <vector>

using namespace std;
// 代码随想录
class Solution 
{
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        if (nums.size() <= 1)
            return nums.size();
        int curDiff = 0;        // 当前一对差值
        int preDiff = 0;        // 前一对差值
        int ans = 1;            // 记录峰值个数， 序列默认序列最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; i++)
        {
            curDiff = nums[i + 1] - nums[i];
            // 出现峰值，坡度发生摆动变化的时候实时更新preDiff
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0))
            {
                ans++;
                preDiff = curDiff;
            }
        }
        return ans; 
    }
};

int main()
{
    vector<int> nums = { 1,2,2,2,3,4 };
    Solution S;
    S.wiggleMaxLength(nums);

    return 0;
}