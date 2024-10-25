#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution 
{
public:
    /*
    // ��������¼ �����ⷨ
    int trap(vector<int>& height) 
    {
        int ans = 0;
        for(int i = 0; i < height.size(); i++)
        {
            // ��һ�������һ�����Ӳ���ˮ
            if (i == 0 || i == height.size() - 1)
                continue;
            // ��¼���ұ����ӵ���߶�
            int rHeight = height[i];
            int lHeight = height[i];
            for (int r = i + 1; r < height.size(); r++)
                if (height[r] > rHeight)
                    rHeight = height[r];
            for (int l = i - 1; l >= 0; l--)
                if (height[l] > lHeight)
                    lHeight = height[l];
            int h = min(lHeight, rHeight) - height[i];
            if (h > 0)
                ans += h;
        }
        return ans;
    }
    
    // ��������¼ ˫ָ�뷨
    int trap(vector<int>& height)
    {
        if (height.size() <= 2)
            return 0;
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        int size = height.size();
        int ans = 0;
        // ��¼ÿ������������߶�
        maxLeft[0] = height[0];
        for (int i = 1; i < size; i++)
        {
            maxLeft[i] = max(height[i], maxLeft[i - 1]);
        }
        // ��¼ÿ�������ұ����߶�
        maxRight[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--)
        {
            maxRight[i] = max(height[i], maxRight[i + 1]);
        }
        // ���
        for (int i = 0; i < size; i++)
        {
            int count = min(maxLeft[i], maxRight[i]) - height[i];
            if (count > 0)
                ans += count;
        }
        return ans;
    }
    */
    // ��������¼ ����ջ
    int trap(vector<int>& height)
    {
        if (height.size() <= 2)
            return 0;
        stack<int> st;
        st.push(0);
        int ans = 0;
        for (int i = 1; i < height.size(); i++)
        {
            if (height[st.top() > height[i]])
                st.push(i);
            else if (height[st.top()] == height[i])
            {
                st.pop();
                st.push(i);
            }
            else if (height[st.top()] < height[i])
            {
                while (!st.empty() && height[st.top()] < height[i])
                {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty())
                    {
                        int h = min(height[st.top()], height[i]) - height[mid];
                        int w = i - st.top() - 1;
                        ans += h * w;
                    }
                }
                st.push(i);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };

    Solution S;
    S.trap(height);

    return 0;
}