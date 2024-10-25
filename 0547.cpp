#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
class Solution 
{
public:
    //非递归
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        if (isConnected.empty() || isConnected[0].empty())
            return 0;
        int m = isConnected.size(), n = isConnected[0].size();
        int count = 0;
        vector<int> visited(isConnected.size(), 0);
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (visited[i] == 1)
                continue;
            for (int j = 0; j < isConnected[0].size(); j++)
            {
                if (isConnected[i][j] == 1)
                {
                    stack<int> friends;
                    if(i == j && visited[i] == 0)
                        friends.push(i);
                    else
                    {
                        if (visited[i] == 0)
                            friends.push(i);
                        if (visited[j] == 0)
                            friends.push(j);
                    }
                    
                    isConnected[i][j] = 0;
                    while (!friends.empty())
                    {
                        auto r = friends.top();
                        friends.pop();
                        if (visited[r] == 1 && i != j)      //若i==j跳过，则可能遗漏朋友圈
                            continue;
                        isConnected[r][r] = 0;
                        for (int k = 0; k < isConnected[0].size(); k++)
                        {
                            if (isConnected[r][k] == 1)
                            {
                                if(visited[k] == 0)
                                    friends.push(k);
                                isConnected[r][k] = 0;
                            }
                        }
                        visited[r] = 1;
                    }
                    count++;
                }
            }
            visited[i] = 1;
        }
        return count;
    }
};
*/
class Solution
{
public:
    //递归
    //主函数
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size(), count = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                DFS(isConnected, i, visited);
                count++;
            }
        }
        return count;
    }
    //辅函数
    void DFS(vector<vector<int>>& isConnected, int i, vector<bool>& visited)
    {
        visited[i] = true;
        for (int k = 0; k < isConnected.size(); k++)
        {
            if (isConnected[i][k] == 1 && !visited[k])
                DFS(isConnected, k, visited);
        }
    }
};
int main()
{
    vector<vector<int>> isConnected = { {1, 0, 0, 1},{0, 1, 1, 0},{0, 1, 1, 1},{1, 0, 1, 1} };
    Solution S;
    S.findCircleNum(isConnected);

    return 0;
}