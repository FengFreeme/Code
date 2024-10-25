#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int MinIndex = 0;

        for (int i = 0; i < k; i++)
        {
            nums[MinIndex] = -nums[MinIndex];
            if (MinIndex < n - 1 && nums[MinIndex] > nums[MinIndex + 1])
            {
                MinIndex = MinIndex + 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += nums[i];
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = { 2,-3,-1,5,-4 };
    int k = 2;
    Solution S;
    S.largestSumAfterKNegations(nums, k);

    return 0;
}