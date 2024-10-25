#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
/*
bool compare(vector<int> a, vector<int> b)
{
    if (a[1] < b[1])
        return a[1] < b[1];
    else if (a[1] == b[1])
        return a[0] < b[0];
    return false;
}
*/
bool compare(vector<int> a, vector<int> b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] > b[0];
}
class Solution 
{
public:
    /*
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        vector<vector<int>> ans;
        sort(people.begin(), people.end(), compare);
        int size = people.size();
        stack<vector<int>> t;
        for (int i = 0; i < people.size(); i++)
        {
            if (people[i][1] == 0)
            {
                ans.push_back(people[i]);
                continue;
            }
            int num = 0;
            for (int j = 0; j < ans.size(); j++)
            {
                if (ans[j][0] >= people[i][0])
                {
                    num++;
                    if (num == people[i][1])
                    {
                        int count = ans.size() - 1;
                        while (count != j && ans[count][1] != people[i][1])
                        {
                            t.push(ans[count]);
                            ans.pop_back();
                            count--;
                        }
                        ans.push_back(people[i]);
                        while (!t.empty())
                        {
                            ans.push_back(t.top());
                            t.pop();
                        }
                        break;
                    }
                }
                
            }
        }
        return ans;
    }
    */
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> que;
        for (int i = 0; i < people.size(); i++)
        {
            int position = people[i][1];
            que.insert(que.begin() + position, people[i]);
        }
        return que;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end(), compare);
        // list 底层是链表实现，插入效率比 vector 高得多
        list<vector<int>> que;
        for (int i = 0; i < people.size(); i++)
        {
            // 插入到下标为 position 的位置
            // ::iterator: 是list容器的一个嵌套类型，它提供了迭代器，用于遍历list中的元素。
            // 迭代器类似于指针，可以用来访问容器中的元素，并可以进行递增（++）和递减（--）操作以遍历容器。
            list<vector<int>>::iterator it = que.begin();
            
            int position = people[i][1];
            while (position--)
                it++;
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};

int main()
{
    vector<vector<int>> people = { {7, 0},{4, 4},{7, 1},{5, 0},{6, 1},{5, 2} };

    Solution S;
    vector<vector<int>> ans = S.reconstructQueue(people);

    return 0;
}