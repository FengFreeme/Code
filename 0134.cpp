#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    /*
    // 暴力解法
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        
        int n = gas.size();
        int stop;
        int remain;
        for (int i = 0; i < n; i++)
        {
            
            stop = 0;
            remain = gas[i];
            int Index = i;
            if (remain < cost[Index])
                continue;
            while(stop != n)
            {
                if (remain >= cost[Index])
                {
                    stop++;
                    
                    if (Index == n - 1)
                    {
                        remain = remain - cost[Index] + gas[0];
                        Index = 0;
                    }
                    else
                    {
                        remain = remain - cost[Index] + gas[Index + 1];
                        Index++;
                    }
                }
                else
                    break;
            }
            if (stop == n)
                return i;
        }
        return -1;
    }
    // 贪心（是不是贪心有待考究）
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int curSum = 0;
        int min = INT_MAX;
        for (int i = 0; i < gas.size(); i++)
        {
            int rest = gas[i] - cost[i];
            curSum += rest;
            if (curSum < min)
                min = curSum;
        }
        if (curSum < 0)
            return -1;
        if (min >= 0)
            return 0;
        for (int i = gas.size() - 1; i >= 0; i--)
        {
            int rest = gas[i] - cost[i];
            min += rest;
            if (min >= 0)
                return i;
        }
        return +1;
    }
    */
    // 贪心
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0)
            {
                start = i + 1;
                curSum = 0;
            }
        }
        if (totalSum < 0)
            return -1;
        return start;
    }
};

int main()
{
    vector<int> gas = { 1,2,3,4,5 };
    vector<int> cost = { 3,4,5,1,2 };

    Solution S;
    S.canCompleteCircuit(gas, cost);

    return 0;
}