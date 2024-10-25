#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    /*
    // 代码随想录 方法一
    int jump(vector<int>& nums) 
    {
        if (nums.size() == 1)
            return 0; 
        // 当前覆盖最远距离下标
        int curDistance = 0;
        int ans = 0;
        // 下一步覆盖最远距离下标
        int nextDistance = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // 更新下一步覆盖最远距离下标
            nextDistance = max(i + nums[i], nextDistance);
            if (i == curDistance)
            {
                ans++;
                curDistance = nextDistance;
                if (nextDistance >= nums.size() - 1)
                    break;
            }
        }
        return ans;
    }
    */
    // 代码随想录 方法二
    int jump(vector<int>& nums)
    {
        // 当前覆盖最远距离下标
        int curDistance = 0;
        int ans = 0;
        // 下一步覆盖最远距离下标
        int nextDistance = 0;
        // 注意这里是i < nums.size()
        for (int i = 0; i < nums.size() - 1; i++)
        {
            // 更新下一步覆盖最远距离下标
            nextDistance = max(i + nums[i], nextDistance);
            if (i == curDistance)
            {
                ans++;
                curDistance = nextDistance;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = { 2,1,1 };

    Solution S;
    S.jump(nums);

    return 0;
}