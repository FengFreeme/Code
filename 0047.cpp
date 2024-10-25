#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used1 = vector<bool>(8, false);
    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        backtracking(nums);

        return ans;
    }
    // 1. ȷ������
    void backtracking(vector<int> nums)
    {
        // 2. ȷ����ֹ����
        if (path.size() == nums.size())
        {
            ans.push_back(path);
            return;
        }
        // ����Ԫ��ȥ��
        vector<bool> used2 = vector<bool>(21, false);
        // 3. ���εݹ鴦��
        for (int i = 0; i < nums.size(); i++)
        {
            if (used1[i] == true || used2[nums[i] + 10] == true)
                continue;
            used2[nums[i] + 10] = true;
            path.push_back(nums[i]);
            used1[i] = true;
            backtracking(nums);
            used1[i] = false;
            path.pop_back();
        }
        return;
    }
};

int main()
{
    vector<int> nums = { 1,1,2 };

    Solution S;
    S.permuteUnique(nums);

    return 0;
}