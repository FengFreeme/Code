#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        int n = nums.size();
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++)
        {
            umap[nums[i]]++;
        }
        vector<int> ans;
        int num = 0;
        
        for (int i = 0; i < k; i++)
        {
            int max_num = 0;
            int num = 0;
            for (auto j : umap)
            {
                if (max_num < j.second)
                {
                    max_num = j.second;
                    num = j.first;
                }
            }
            ans.push_back(num);
            umap.erase(num);
        }
        return ans;
    }
    // 小顶堆
    class mycomparison
    {
    public:
        // 重载了operator()，用于比较两个pair<int, int>对象
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
        {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            umap[nums[i]]++;
        }
        // 对频率排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        for (unordered_map<int, int>::iterator it = umap.begin(); it != umap.end(); it++)
        {
            pri_que.push(*it);
            if (pri_que.size() > k)
                pri_que.pop();
        }
        // 找出前k个高频元素，倒序输出
        vector<int> ans(k);
        for (int i = k - 1; i >= 0; i--)
        {
            ans[i] = pri_que.top().first;
            pri_que.pop();
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = { 1,1,1,2,2,3 };
    int k = 2;

    Solution S;
    S.topKFrequent(nums, k);

    return 0;
}