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
    // С����
    class mycomparison
    {
    public:
        // ������operator()�����ڱȽ�����pair<int, int>����
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
        // ��Ƶ������
        // ����һ��С���ѣ���СΪk
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        for (unordered_map<int, int>::iterator it = umap.begin(); it != umap.end(); it++)
        {
            pri_que.push(*it);
            if (pri_que.size() > k)
                pri_que.pop();
        }
        // �ҳ�ǰk����ƵԪ�أ��������
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