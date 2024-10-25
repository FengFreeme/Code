#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MyQueue 
{
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() 
    {

    }

    void push(int x) 
    {
        stIn.push(x);
    }

    int pop() 
    {
        if (stOut.empty())
        {
            while (!stIn.empty())
            {
                int x = stIn.top();
                stOut.push(x);
                stIn.pop();
            }
        }
        int x = stOut.top();
        stOut.pop();
        return x;
    }

    int peek() 
    {
        int x = pop();
        stOut.push(x);

        return x;
    }

    bool empty() 
    {
        if (stIn.empty() && stOut.empty())
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyQueue *queue = new MyQueue();
    queue->push(1);
    queue->push(2);
    queue->pop();   // 注意此时的输出栈的操作
    queue->push(3);
    queue->push(4);
    queue->pop();
    queue->pop();   // 注意此时的输出栈的操作
    queue->pop();
    queue->empty();

    return 0;
}