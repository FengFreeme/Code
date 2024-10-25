#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    /*
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> uset;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
            uset.insert(nums1[i]);
        bool flag;
        for (int i = 0; i < nums2.size(); i++)
        {
            // δ�ҵ�ʱ����end()������
            // �ҵ�Ԫ��
            if (uset.find(nums2[i]) != uset.end())
            {
                // flag�ж��Ƿ����ظ���ֵ��false˵��û���ظ�
                flag = false;
                for (int j = 0; j < ans.size(); j++)
                {
                    // ˵�����ظ���ֵ
                    if (ans[j] == nums2[i])
                    {
                        flag = true;
                        break;
                    }  
                }
                // û���ظ������뽻��
                if (!flag)
                    ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
    */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> result_set;      // ȥ��
        unordered_set<int> num_set(nums1.begin(), nums1.end());
        for (int i = 0; i < nums2.size(); i++)
        {
            // ���ֹ�
            if (num_set.find(nums2[i]) != num_set.end())
                result_set.insert(nums2[i]);
        }
        // ��setת��vector
        return vector<int>(result_set.begin(), result_set.end());
    }
};