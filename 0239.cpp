#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> ans;
        int n = nums.size();
        if (k >= n)
        {
            int max_num = Max(nums, 0, n);
            ans.push_back(max_num);
            return ans;
        }
        queue<int> slide_window;
        // 求前k个值中最大值
        int max_num = Max(nums, 0, k);
        for (int i = 0; i < k; i++)
            slide_window.push(nums[i]);
        ans.push_back(max_num);
        for (int i = k; i < n; i++)
        {
            int num = slide_window.front();
            slide_window.pop();
            slide_window.push(nums[i]);
            if (num == ans.back())
            {
                max_num = Max(nums, i - k + 1, i + 1);
                ans.push_back(max_num);
            }
            else
            {
                if (ans.back() < nums[i])
                {
                    max_num = nums[i];
                }
                ans.push_back(max_num);
            }
        }
        return ans;
    }
    int Max(vector<int> nums, int low, int high)
    {
        int max_num = nums[low];
        for (int i = low + 1; i < high; i++)
        {
            if (max_num < nums[i])
                max_num = nums[i];
        }
        return max_num;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        MyQueue que;
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            que.push(nums[i]);
        }
        ans.push_back(que.front());
        for (int i = k; i < nums.size(); i++)
        {
            // 滑动窗口移除前面元素
            que.pop(nums[i - k]);
            que.push(nums[i]);
            ans.push_back(que.front());
        }
        return ans;
    }
private:
    // 实现单调队列
    class MyQueue
    {
    public:
        deque<int> que;

        void pop(int value)
        {
            if (!que.empty() && value == que.front())
            {
                que.pop_front();
            }
        }
        void push(int value)
        {
            while (!que.empty() && value > que.back())
            {
                que.pop_back();
            }
            que.push_back(value);
        }
        int front()
        {
            return que.front();
        }
    };
};

int main()
{
    vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k = 3;
    Solution S;
    S.maxSlidingWindow(nums, k);

    return 0;
}