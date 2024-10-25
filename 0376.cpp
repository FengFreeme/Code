#include <iostream>
#include <vector>

using namespace std;
// ��������¼
class Solution 
{
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        if (nums.size() <= 1)
            return nums.size();
        int curDiff = 0;        // ��ǰһ�Բ�ֵ
        int preDiff = 0;        // ǰһ�Բ�ֵ
        int ans = 1;            // ��¼��ֵ������ ����Ĭ���������ұ���һ����ֵ
        for (int i = 0; i < nums.size() - 1; i++)
        {
            curDiff = nums[i + 1] - nums[i];
            // ���ַ�ֵ���¶ȷ����ڶ��仯��ʱ��ʵʱ����preDiff
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0))
            {
                ans++;
                preDiff = curDiff;
            }
        }
        return ans; 
    }
};

int main()
{
    vector<int> nums = { 1,2,2,2,3,4 };
    Solution S;
    S.wiggleMaxLength(nums);

    return 0;
}