#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        backtracking(nums, 0);

        return ans;
    }
    // 1. ȷ������
    void backtracking(vector<int> nums, int startIndex)
    {
        // 3. ���εݹ鴦��
        ans.push_back(path);
        // 2. ȷ����ֹ����
        if (startIndex >= nums.size())
            return;
        // 3. ���εݹ鴦��
        for (int i = startIndex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
        return;
    }
};

int main()
{
    vector<int> nums = { 1,2,3 };

    Solution S;
    S.subsets(nums);

    return 0;
}