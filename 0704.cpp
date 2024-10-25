#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    /*
    int search(vector<int>& nums, int target) 
    {
        int len = nums.size();
        int low = 0, high = len - 1;
        int mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else if (nums[mid] > target)
                high = mid - 1;
        }
        return -1;
    }
    */
    int search(vector<int>& nums, int target)
    {
        int len = nums.size();
        int low = 0, high = len;    //[low, high)
        int mid;
        while (low < high)
        {
            mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else if (nums[mid] > target)
                high = mid;
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = { -1,0,3,5,9,12 };
    int target = 9;

    Solution S;
    cout << S.search(nums, target);

    return 0;
}