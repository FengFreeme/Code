#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums1.size(); i++)
        {
            umap[nums1[i]] = i;
        }
        stack<int> st;
        st.push(0);
        vector<int> ans(nums1.size(), -1);
        for (int i = 1; i < nums2.size(); i++)
        {
            if (nums2[st.top()] >= nums2[i])
                st.push(i);
            else if (nums2[st.top()] < nums2[i])
            {
                while (!st.empty() && nums2[st.top()] < nums2[i])
                {
                    if (umap.find(nums2[st.top()]) != umap.end())
                    {
                        int index = umap[nums2[st.top()]];
                        ans[index] = nums2[i];
                    }
                    st.pop();
                }
                st.push(i);
            }
        }
        return ans;
    }
};