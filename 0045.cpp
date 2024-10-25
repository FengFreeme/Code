#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    /*
    // ��������¼ ����һ
    int jump(vector<int>& nums) 
    {
        if (nums.size() == 1)
            return 0; 
        // ��ǰ������Զ�����±�
        int curDistance = 0;
        int ans = 0;
        // ��һ��������Զ�����±�
        int nextDistance = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // ������һ��������Զ�����±�
            nextDistance = max(i + nums[i], nextDistance);
            if (i == curDistance)
            {
                ans++;
                curDistance = nextDistance;
                if (nextDistance >= nums.size() - 1)
                    break;
            }
        }
        return ans;
    }
    */
    // ��������¼ ������
    int jump(vector<int>& nums)
    {
        // ��ǰ������Զ�����±�
        int curDistance = 0;
        int ans = 0;
        // ��һ��������Զ�����±�
        int nextDistance = 0;
        // ע��������i < nums.size()
        for (int i = 0; i < nums.size() - 1; i++)
        {
            // ������һ��������Զ�����±�
            nextDistance = max(i + nums[i], nextDistance);
            if (i == curDistance)
            {
                ans++;
                curDistance = nextDistance;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = { 2,1,1 };

    Solution S;
    S.jump(nums);

    return 0;
}