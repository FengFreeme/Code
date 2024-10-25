#include <vector>
#include <iostream>

using namespace std;
/*
//方法一
class Solution 
{
public:
    bool search(vector<int>& nums, int target) 
    {
        int k = nums.size(), len = nums.size();
        for (int i = 0; i < len - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                k = i + 1;
                break;
            }
        }
        int index = -1;
        if (target >= nums[0])
            index = BSearch(nums, 0, k - 1, target);
        else
            index = BSearch(nums, k, len - 1, target);
        if (index == -1)
            return false;
        else
            return true;
    }
    int BSearch(vector<int>& nums, int l, int r, int target)
    {
        int mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                r = mid - 1;
            else if (nums[mid] < target)
                l = mid + 1;
        }
        return -1;
    }
};
*/
//方法二 书上
class Solution
{
public:
    bool search(vector<int>& nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[start] == nums[mid])    //无法判断哪个区间增序
                start++;
            else if (nums[mid] <= nums[end])
            {
                if (target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            else
            {
                if (target >= nums[start] && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }

        }
        return false;
    }
};
int main()
{
    vector<int> nums = { 2,5,6,0,0,1,2 };
    int target = 0;

    Solution S;
    S.search(nums, target);

    return 0;
}