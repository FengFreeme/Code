#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    /*
    * //暴力解法
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int len = nums.size();
        int minLength = INT_MAX;
        int sum, Length;
        for (int i = 0; i < len; i++)
        {
            sum = 0, Length = 0;
            for (int j = i; j < len; j++)
            {
                sum = sum + nums[j];
                Length++;
                if (sum >= target)
                {
                    minLength = min(minLength, Length);
                    break;
                }
            }
        }
        if (minLength == INT_MAX)
            return 0;
        else
            return minLength;
    }
    */
    /*
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int len = nums.size();
        int minLength = INT_MAX;
        int sum = 0, Length = 0;
        for (int slow = 0, fast = 0; fast < len;)
        {
            if (sum >= target)
            {
                minLength = min(minLength, Length);
                sum = sum - nums[slow];
                slow++;
                Length--;
            }
            else if (sum < target)
            {
                sum += nums[fast];
                Length++;
            }
            if (sum < target)
                fast++;
        }
        if (minLength != INT_MAX)
            return minLength;
        else
            return 0;
    }
    */
    // 书上写法
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int result = INT_MAX;
        int sum = 0;
        int i = 0;      //窗口起始位置
        int Length = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while (sum >= target)
            {
                Length = (j - i + 1);
                result = min(result, Length);
                sum -= nums[i];     //变更窗口起始位置
                i++;
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};

int main()
{
    vector<int> nums = { 2,3,1,2,4,3 };
    int target = 7;

    Solution S;
    S.minSubArrayLen(target, nums);

    return 0;
}