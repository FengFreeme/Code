#include <iostream>
#include <vector>

using namespace std;
/*
//方法一
class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size() - 1;
        int mid, first = -1, last = -1;
        int flag = 0;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[mid] == target)
            {
                flag = 1;
                break;
            }
            else if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] > target)
                r = mid - 1;
        }    
        if(flag == 1)
        {
            //在使用数组元素之前可以将判断下标溢出判断语句放在&&前面
            int temp = mid;
            while (temp >= 0 && nums[temp] == target)
                temp--;
            first = temp + 1;
            temp = mid;
            while (temp < nums.size() && nums[temp] == target)
                temp++;
            last = temp - 1;
            return { first, last };
        }
        return { -1, -1 };
    }
};
*/
//方法二 多理解
class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if (nums.empty())
            return { -1, -1 };
        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target) - 1;
        if (lower == nums.size() || nums[lower] != target)
            return { -1, -1 };
        return { lower, upper };
    }
    int lower_bound(vector<int>& nums, int target)      //查找不小于target的元素
    {
        int l = 0, r = nums.size(), mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (nums[mid] >= target)
                r = mid;
            else if (nums[mid] < target)
                l = mid + 1;
        }
        return l;
    }
    int upper_bound(vector<int>& nums, int target)      //查找第一个大于terget的元素
    {
        int l = 0, r = nums.size(), mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (nums[mid] > target)
                r = mid;
            else if (nums[mid] <= target)
                l = mid + 1;
        }
        return l;
    }
};

int main()
{
    vector<int> nums = {1};
    int target = 1;
    Solution S;

    S.searchRange(nums, target);

    return 0;
}