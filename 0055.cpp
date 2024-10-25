#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    // ��������¼
    bool canJump(vector<int>& nums) 
    {
        int cover = 0;
        // ֻ��һ��Ԫ�أ���㼴�յ�
        if (nums.size() == 1)
            return true;
        for (int i = 0; i <= cover; i++)
        {
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1)
                return true;
        }
        return false;
    }
};

int main()
{
    vector<int> nums = { 3,2,1,0,4 };

    Solution S;
    S.canJump(nums);

    return 0;
}