#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int a, b;
        for (int i = 0; i < n; i++)
        {
            // 剪枝处理 在搜索算法中，剪枝通常指的是在搜索过程中提前终止那些不可能找到解的路径的搜索
            if ((nums[i] > target && target >= 0) || nums[i] >= 0 && target < 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            a = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                // 二级剪枝处理
                if ((nums[i] + nums[j] > target && target >= 0) || nums[i] + nums[j] >= 0 && target < 0)
                    break;
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                b = nums[j];
                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    if (left > j + 1 && nums[left] == nums[left - 1])
                    {
                        left++;
                        continue;
                    }
                    if (right < n - 1 && nums[right] == nums[right + 1])
                    {
                        right--;
                        continue;
                    }
                    // 通过将其中一个操作数（在这里是 a）显式地转换为 long 类型，可以确保整个表达式的计算是在 long 类型的范围内进行的
                    if ((long)a + b + nums[left] + nums[right] == target)
                    {
                        ans.push_back({ a, b, nums[left], nums[right] });
                        left++;
                        right--;
                    }
                    else if ((long)a + b + nums[left] + nums[right] > target)
                        right--;
                    else if ((long)a + b + nums[left] + nums[right] < target)
                        left++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = { 1,-2,-5,-4,-3,3,3,5 };
    int target = -11;

    Solution S;
    S.fourSum(nums, target);

    return 0;
}