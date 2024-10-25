#include <iostream>
#include <vector>
using namespace std;
/*
class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        vector<int> Tempnums1(nums1);
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (Tempnums1[i] <= nums2[j])
            {
                nums1[k] = Tempnums1[i];
                i++;
            }
            else if (Tempnums1[i] > nums2[j])
            {
                nums1[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < m)
        {
            nums1[k] = Tempnums1[i];
            i++;
            k++;
        }
        while (j < n)
        {
            nums1[k] = nums2[j];
            j++;
            k++;
        }
    }
};
*/
class Solution
{
public:
    //先排大的不会破坏顺序
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = m - 1, j = n - 1;
        int k = nums1.size() - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            }
            else if (nums1[i] <= nums2[j])
            {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while (j >= 0)
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

int main()
{
    vector<int> nums1 = { 0 }, nums2 = { 1 };
    int m = 0, n = 1;
    Solution S;
    S.merge(nums1, m, nums2, n);

    return 0;
}