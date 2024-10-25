#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int removeElement1(vector<int>& nums, int val) 
    {
        int n = nums.size(), sum = n;
        // 指向最后一个有效的元素
        int change = n - 1;
        for (int i = 0; i <= change;)
        {
            // 注意可能出现 nums[change]==val 的情况
            if (nums[i] == val)
            {
                int temp = nums[change];
                nums[change] = nums[i];
                nums[i] = temp;
                change--;
                sum--;
            }
            else
                i++;
        }
        return sum;
    }
    int removeElement(vector<int>& nums, int val)
    {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
        {
            if (val != nums[fastIndex])
                nums[slowIndex++] = nums[fastIndex];
        }
        return slowIndex;
    }
};

int main()
{
    vector<int> nums = { 3, 2, 2, 3 };
    int val = 3;
    Solution S;
    S.removeElement(nums, val);

    return 0;
}