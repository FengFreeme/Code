#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int a, b;
        for (int i = 0; i < n; i++)
        {
            // ��֦���� �������㷨�У���֦ͨ��ָ������������������ǰ��ֹ��Щ�������ҵ����·��������
            if ((nums[i] > target && target >= 0) || nums[i] >= 0 && target < 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            a = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                // ������֦����
                if ((nums[i] + nums[j] > target && target >= 0) || nums[i] + nums[j] >= 0 && target < 0)
                    break;
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                b = nums[j];
                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    if (left > j + 1 && nums[left] == nums[left - 1])
                    {
                        left++;
                        continue;
                    }
                    if (right < n - 1 && nums[right] == nums[right + 1])
                    {
                        right--;
                        continue;
                    }
                    // ͨ��������һ������������������ a����ʽ��ת��Ϊ long ���ͣ�����ȷ���������ʽ�ļ������� long ���͵ķ�Χ�ڽ��е�
                    if ((long)a + b + nums[left] + nums[right] == target)
                    {
                        ans.push_back({ a, b, nums[left], nums[right] });
                        left++;
                        right--;
                    }
                    else if ((long)a + b + nums[left] + nums[right] > target)
                        right--;
                    else if ((long)a + b + nums[left] + nums[right] < target)
                        left++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = { 1,-2,-5,-4,-3,3,3,5 };
    int target = -11;

    Solution S;
    S.fourSum(nums, target);

    return 0;
}