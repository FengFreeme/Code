#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MyStack 
{
public:
    queue<int> que1;
    queue<int> que2;
    MyStack() 
    {

    }

    void push(int x) 
    {
        que1.push(x);
    }

    int pop() 
    {
        int len = que1.size();
        while (len > 1)
        {
            int x = que1.front();
            que2.push(x);
            que1.pop();
            len--;
        }
        int res = que1.front();
        que1.pop();
        while (!que2.empty())
        {
            int x = que2.front();
            que1.push(x);
            que2.pop();
        }
        return res;
    }

    int top() 
    {
        return que1.back();
    }

    bool empty() 
    {
        if (que1.empty())
            return true;
        else
            return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */