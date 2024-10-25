#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution 
{
public:
    /*
    // ˫ָ��ⷨ
    int largestRectangleArea(vector<int>& heights) 
    {
        vector<int> minLeftIndex(heights.size());
        vector<int> minRightIndex(heights.size());
        int size = heights.size();
        // ��Ϊ�������ǰ���Ӹ߶����ܸ��ǵ�������
        // ��¼ÿ������ ��ߵ�һ��С�ڸ����ӵ��±�
        minLeftIndex[0] = -1;
        for (int i = 1; i < size; i++)
        {
            int t = i - 1;
            while (t >= 0 && heights[t] >= heights[i])
                t = minLeftIndex[t];
            minLeftIndex[i] = t;
        }
        // ��¼ÿ������ �ұߵ�һ��С�ڸ����ӵ��±�
        minRightIndex[size - 1] = size;
        for (int i = size - 2; i >= 0; i--)
        {
            int t = i + 1;
            while (t < size && heights[t] >= heights[i])
                t = minRightIndex[t];
            minRightIndex[i] = t;
        }
        // ��� 
        int ans = 0;
        for (int i = 0; i < size; i++)
        {
            int sum = heights[i] * (minRightIndex[i] - minLeftIndex[i] - 1);
            ans = max(ans, sum);
        }
        return ans;
    }
    */
    // ����ջ ��ǿ��
    int largestRectangleArea(vector<int>& heights)
    {
        if (heights.size() == 1)
            return heights[0];
        stack<int> st;
        // ����ͷ������Ԫ�� 0
        heights.insert(heights.cbegin(), 0);
        heights.push_back(0);
        int size = heights.size();

        st.push(0);
        int ans = 0;
        for (int i = 1; i < size; i++)
        {
            if (heights[st.top()] < heights[i])
                st.push(i);
            else if(heights[st.top()] == heights[i])
            {
                st.pop();
                st.push(i);
            }
            else if (heights[st.top()] > heights[i])
            {
                while (!st.empty() && heights[st.top()] > heights[i])
                {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty())
                    {
                        int h = heights[mid];
                        int w = i - st.top() - 1;
                        ans = max(ans, h * w);
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
    vector<int> heights = { 2,1,5,6,2,3 };

    Solution S;
    S.largestRectangleArea(heights);

    return 0;
}