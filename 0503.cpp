#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution 
{
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        vector<int> ans = vector<int>(nums.size(), -1);
        if (nums.size() == 1)
            return ans;
        stack<int> st;
        st.push(0);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[st.top()] >= nums[i])
                st.push(i);
            else if (nums[st.top()] < nums[i])
            {
                while (!st.empty() && nums[st.top()] < nums[i])
                {
                    ans[st.top()] = nums[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            // 判断ans[st.top()] == -1，避免原来的值被覆盖，不用担心被误更新，而且如果早就右更大的下一个值，早就更新了
            if (nums[st.top()] < nums[i] && ans[st.top()] == -1)
            {
                while (!st.empty() && nums[st.top()] < nums[i] && ans[st.top()] == -1)
                {
                    ans[st.top()] = nums[i];
                    st.pop();
                }
            }

            if (st.empty())
                break;
        }
        return ans;
    }
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        vector<int> ans = vector<int>(nums.size(), -1);
        if (nums.size() == 1)
            return ans;
        stack<int> st;
        st.push(0);
        for (int i = 1; i < nums.size() * 2; i++)
        {
            if (nums[st.top()] >= nums[i % nums.size()])
                st.push(i % nums.size());
            else if (nums[st.top()] < nums[i % nums.size()])
            {
                while (!st.empty() && nums[st.top()] < nums[i % nums.size()])
                {
                    ans[st.top()] = nums[i % nums.size()];
                    st.pop();
                }
                st.push(i % nums.size());
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = { 1,2,3,4,3 };
    Solution S;
    S.nextGreaterElements(nums);

    return 0;
}