#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> threeSum1(vector<int>& nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            unordered_set<int> uset;
            for (int j = i + 1; j < nums.size(); j++)
            {
                // 说明当前元素 nums[j] 与其前两个元素都相同
                // 这意味着我们已经使用 nums[j - 1] 和 nums[j - 2] 与 nums[i] 组成过三元组
                // 因此 nums[j] 再与 nums[i] 组合会产生重复的三元组
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2])
                    continue;
                int c = 0 - (nums[i] + nums[j]);
                if (uset.find(c) != uset.end())
                {
                    ans.push_back({ nums[i], nums[j], c });
                    // 删除元素
                    uset.erase(c);
                }
                else
                    uset.insert(nums[j]);
            }
        }
        return ans;
    }
    vector<vector<int>> threeSum2(vector<int>& nums)
    {
        vector<vector<int>> ans;
        int low, high;
        int n = nums.size();
        int target;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                return ans;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            target = 0 - nums[i];
            low = i + 1, high = n - 1;
            while (low < high)
            {
                if (nums[low] + nums[high] == target)
                {
                    ans.push_back({ nums[i], nums[low], nums[high] });
                    while (low < high && nums[low] == nums[low + 1])
                        low++;
                    while (low < high && nums[high] == nums[high - 1])
                        high--;
                    low++;
                    high--;
                } 
                else if (nums[low] + nums[high] > target)
                    high--;
                else if (nums[low] + nums[high] < target)
                    low++;
            }
        }
        return ans;
    }
    // 哈希表 
    vector<vector<int>> threeSum3(vector<int>& nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出 a + b + c = 0
        // a = nums[i], b = nums[j], c = -(a + b)
        // a 和 b 和 c 可以相等
        for (int i = 0; i < nums.size(); i++)
        {
            // 第一个元素大于0，不可能等于0
            if (nums[i] > 0)
                break;
            // 元素a去重
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            unordered_set<int> uset;
            for (int j = i + 1; j < nums.size(); j++)
            {
                // 元素b去重
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2])
                    continue;
                int c = 0 - (nums[i] + nums[j]);
                if (uset.find(c) != uset.end())
                {
                    // 找到了一个解
                    result.push_back({ nums[i], nums[j], c });
                    // 元素c去重
                    uset.erase(c);
                }
                else
                    uset.insert(nums[j]);
            }
        }
        return result;
    }
    // 双指针
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                break;
            int a = nums[i];
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                if (left > i + 1 && nums[left] == nums[left - 1])
                {
                    left++;
                    continue;
                }
                if (right < n - 1 && nums[right] == nums[right + 1])
                {
                    right--;
                    continue;
                }
                if (a + nums[left] + nums[right] == 0)
                {
                    result.push_back({ a, nums[left], nums[right] });
                    left++;
                    right--;
                }
                else if (a + nums[left] + nums[right] > 0)
                    right--;
                else if (a + nums[left] + nums[right] < 0)
                    left++;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = { -2,0,0,2,2 };

    Solution S;
    S.threeSum(nums);

    return 0;
}