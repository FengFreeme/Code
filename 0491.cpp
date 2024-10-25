#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        if (nums.size() <= 1)
            return ans;
        backtracking(nums, 0);

        return ans;
    }
    // ��unordered_setȥ��
    // 1. ȷ������
    void backtracking(vector<int> nums, int startIndex)
    {
        // 2. ȷ����ֹ����
        if (path.size() >= 2)
            ans.push_back(path);
        if (startIndex >= nums.size())
            return;
        // 3. ���εݹ鴦��
        // ʹ��set�Ա���Ԫ�ؽ���ȥ�أ���ͬ������¼�¼
        unordered_set<int> uset; 
        for (int i = startIndex; i < nums.size(); i++)
        {
            if((path.size() == 0 || nums[i] >= path.back()) && uset.find(nums[i]) == uset.end())
            {
                // ��¼Ԫ���ڱ����Ѿ�ʹ�ù��������ٴ�ʹ��
                uset.insert(nums[i]);
                path.push_back(nums[i]);
                backtracking(nums, i + 1);
                path.pop_back();
            }
        }
        return;
    }
};

int main()
{
    vector<int> nums = { 1,2,3,1,1,1 };

    Solution S;
    S.findSubsequences(nums);

    return 0;
}