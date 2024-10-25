#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_set<int> uset;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] == target)
            {
                uset.insert(i);
                uset.insert(j);
            }
            else if (nums[i] + nums[j] > target)
                j--;
            else
                i++;
        }
        return vector<int>(uset.begin(), uset.end());
    }
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int len = nums.size();
        unordered_set<int> uset;
        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    uset.insert(i);
                    uset.insert(j);
                }
            }
        }
        return vector<int>(uset.begin(), uset.end());
    }
    // 只要找两个数就行了
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = umap.find(target - nums[i]);
            // 找到
            if (iter != umap.end())
                return { iter->second, i };
            // 未找到
            else
                umap.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};