#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, 0, used);
        
        return ans;
    }
    /*
    // 1. ȷ������
    void backtracking(vector<int> nums, int startIndex)
    {
        // 2. ȷ����ֹ����
        ans.push_back(path);
        if (startIndex >= nums.size())
            return;
        // 3. ���εݹ鴦��
        for (int i = startIndex; i < nums.size(); i++)
        {
            if (i > startIndex && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
        return;
    }
    */
    // ��������¼ȥ���߼�
    // 1. ȷ������
    void backtracking(vector<int> nums, int startIndex, vector<bool>& used)
    {
        // 2. ȷ����ֹ����
        ans.push_back(path);
        if (startIndex >= nums.size())
            return;
        // 3. ���εݹ鴦��
        for (int i = startIndex; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && used[i-1] == false)
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
        return;
    }
};

int main()
{
    vector<int> nums = { 1,2,2 };
    
    Solution S;
    S.subsetsWithDup(nums);

    return 0;
}