#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    /*
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int len = nums.size();
        for (int i = 0; i < len; i++)
            nums[i] = abs(nums[i]);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++)
            nums[i] = nums[i] * nums[i];
        return nums;
    }
    */
    vector<int> sortedSquares(vector<int>& nums)
    {
        int len = nums.size();
        vector<int> ans(len);
        int left = 0, right = len - 1;
        int size = len;
        while (left <= right)
        {
            if (abs(nums[left]) <= abs(nums[right]))
            {
                ans[size - 1] = nums[right] * nums[right];
                right--;
            }
            else
            {
                ans[size - 1] = nums[left] * nums[left];
                left++;
            }
            size--;
        }
        return ans;
    }
};

