#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    /*
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> uset;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
            uset.insert(nums1[i]);
        bool flag;
        for (int i = 0; i < nums2.size(); i++)
        {
            // 未找到时返回end()迭代器
            // 找到元素
            if (uset.find(nums2[i]) != uset.end())
            {
                // flag判断是否有重复的值，false说明没有重复
                flag = false;
                for (int j = 0; j < ans.size(); j++)
                {
                    // 说明有重复的值
                    if (ans[j] == nums2[i])
                    {
                        flag = true;
                        break;
                    }  
                }
                // 没有重复，加入交集
                if (!flag)
                    ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
    */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> result_set;      // 去重
        unordered_set<int> num_set(nums1.begin(), nums1.end());
        for (int i = 0; i < nums2.size(); i++)
        {
            // 出现过
            if (num_set.find(nums2[i]) != num_set.end())
                result_set.insert(nums2[i]);
        }
        // 将set转成vector
        return vector<int>(result_set.begin(), result_set.end());
    }
};