#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        vector<int> ans(temperatures.size());
        if (temperatures.size() == 1)   
            return ans;

        stack<int> st;
        int i = 0;
        while(!st.empty() || i != temperatures.size())
        {
            if(!st.empty())
            {
                int num = temperatures[st.top()];
                if (temperatures[i] > num)
                {
                    ans[st.top()] = i - st.top();
                    st.pop();
                }
                else
                {
                    st.push(i);
                    i++;
                }
            }
            else
            {
                st.push(i);
                i++;
            }

            if (i == temperatures.size())
                break;
        }
        return ans;
    }
    // ´úÂëËæÏëÂ¼
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> ans(temperatures.size());
        if (temperatures.size() == 1)
            return ans;

        stack<int> st;
        st.push(0);
        for (int i = 1; i < temperatures.size(); i++)
        {
            if (temperatures[st.top()] >= temperatures[i])
                st.push(i);
            else if (temperatures[st.top()] < temperatures[i])
            {
                while (!st.empty() && temperatures[st.top()] < temperatures[i])
                {
                    ans[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> temperatures = { 73,74,75,71,69,72,76,73 };

    Solution S;
    S.dailyTemperatures(temperatures);

    return 0;
}