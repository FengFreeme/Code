#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

bool dictionaryOrder(const vector<string>& a, const vector<string>& b)
{
    int size = a.size();
    for (int i = 0; i < size; i++)
    {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
}
/*
class Solution 
{
public:
    vector<vector<string>> ans;
    vector<string> path;
    // ����Ƿ����ֵ��������ǰ���ֵ�����
    bool flag = false;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        vector<bool> used = vector<bool>(tickets.size(), false);
        path.push_back("JFK");
        backtracking(tickets, used, "JFK");
        // sort(ans.begin(), ans.end(), dictionaryOrder);

        return ans.back();
    }
    // 1. ȷ������
    void backtracking(vector<vector<string>> tickets, vector<bool>& used, string PreviousDestination)
    {
        // 2. ��ֹ����
        if (path.size() == tickets.size() + 1)
        {
            ans.push_back(path);
            flag = false;
            return;
        }
        // 3. ���εݹ鴦��
        for (int i = 0; i < tickets.size(); i++)
        {
            if (tickets[i][0] == PreviousDestination && used[i] == false)
            {
                // ��Ŀǰ���ֵ�������ֵ�Ƚ��Ƿ����ǰ�����������ǰ�򲻼�������
                if (ans.size() != 0 && ans.back()[path.size()] < tickets[i][1] && flag == false)
                    break;
                else
                    flag = true;
                path.push_back(tickets[i][1]);
                used[i] = true;
                backtracking(tickets, used, tickets[i][1]);
                used[i] = false;
                path.pop_back();
            }
        }
    }
    
};
*/

class Solution
{
public:
    // unordered_map<��������, map<�������, �������>> targets
    // ����ö������֮������˳��Ļ���������std::map��һ�Զ�ӳ����������ôʵ��һ�Զ����
    // Ҫʵ��һ�Զ� ����һ��map�ļ���Ӧ��ֵҲ��һ������
    unordered_map<string, map<string, int>> targets;

    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        vector<string> ans;
        // ��¼ӳ���ϵ
        for (const vector<string>& vec : tickets)
        {
            targets[vec[0]][vec[1]]++;
        }
        ans.push_back("JFK");
        // sort(ans.begin(), ans.end(), dictionaryOrder);
        backtracking(tickets.size(), ans);

        return ans;
    }
    // 1. ȷ������
    bool backtracking(int ticketNum, vector<string> &ans)
    {
        // 2. ��ֹ����
        if (ans.size() == ticketNum + 1)
        {
            return true;
        }
        // 3. ���εݹ鴦��
        // ͨ�� targets[ans.back()] ��һ���յ���Ϊ���Ѱ�ұ��ε��յ�
        for (pair<const string, int>& target : targets[ans.back()])
        {
            if (target.second > 0)
            {
                ans.push_back(target.first);
                target.second--;
                if (backtracking(ticketNum, ans))
                    return true;
                ans.pop_back();
                target.second++;
            }
        }
        return false;
    }

};

int main()
{
    // vector<vector<string>> tickets = {{"AXA", "EZE"}, {"EZE", "AUA"}, {"ADL", "JFK"}, {"ADL", "TIA"}, {"AUA", "AXA"}, {"EZE", "TIA"}, {"EZE", "TIA"}, {"AXA", "EZE"}, {"EZE", "ADL"}, {"ANU", "EZE"}, {"TIA", "EZE"}, {"JFK", "ADL"}, {"AUA", "JFK"}, {"JFK", "EZE"}, {"EZE", "ANU"}, {"ADL", "AUA"}, {"ANU", "AXA"}, {"AXA", "ADL"}, {"AUA", "JFK"}, {"EZE", "ADL"}, {"ANU", "TIA"}, {"AUA", "JFK"}, {"TIA", "JFK"}, {"EZE", "AUA"}, {"AXA", "EZE"}, {"AUA", "ANU"}, {"ADL", "AXA"}, {"EZE", "ADL"}, {"AUA", "ANU"}, {"AXA", "EZE"}, {"TIA", "AUA"}, {"AXA", "EZE"}, {"AUA", "SYD"}, {"ADL", "JFK"}, {"EZE", "AUA"}, {"ADL", "ANU"}, {"AUA", "TIA"}, {"ADL", "EZE"}, {"TIA", "JFK"}, {"AXA", "ANU"}, {"JFK", "AXA"}, {"JFK", "ADL"}, {"ADL", "EZE"}, {"AXA", "TIA"}, {"JFK", "AUA"}, {"ADL", "EZE"}, {"JFK", "ADL"}, {"ADL", "AXA"}, {"TIA", "AUA"}, {"AXA", "JFK"}, {"ADL", "AUA"}, {"TIA", "JFK"}, {"JFK", "ADL"}, {"JFK", "ADL"}, {"ANU", "AXA"}, {"TIA", "AXA"}, {"EZE", "JFK"}, {"EZE", "AXA"}, {"ADL", "TIA"}, {"JFK", "AUA"}, {"TIA", "EZE"}, {"EZE", "ADL"}, {"JFK", "ANU"}, {"TIA", "AUA"}, {"EZE", "ADL"}, {"ADL", "JFK"}, {"ANU", "AXA"}, {"AUA", "AXA"}, {"ANU", "EZE"}, {"ADL", "AXA"}, {"ANU", "AXA"}, {"TIA", "ADL"}, {"JFK", "ADL"}, {"JFK", "TIA"}, {"AUA", "ADL"}, {"AUA", "TIA"}, {"TIA", "JFK"}, {"EZE", "JFK"}, {"AUA", "ADL"}, {"ADL", "AUA"}, {"EZE", "ANU"}, {"ADL", "ANU"}, {"AUA", "AXA"}, {"AXA", "TIA"}, {"AXA", "TIA"}, {"ADL", "AXA"}, {"EZE", "AXA"}, {"AXA", "JFK"}, {"JFK", "AUA"}, {"ANU", "ADL"}, {"AXA", "TIA"}, {"ANU", "AUA"}, {"JFK", "EZE"}, {"AXA", "ADL"}, {"TIA", "EZE"}, {"JFK", "AXA"}, {"AXA", "ADL"}, {"EZE", "AUA"}, {"AXA", "ANU"}, {"ADL", "EZE"}, {"AUA", "EZE"}};
    vector<vector<string>> tickets = { {"JFK", "NRT"}, {"JFK", "KUL"}, {"NRT", "JFK"} };
    // vector<vector<string>> tickets = { {"EZE", "AXA"}, {"TIA", "ANU"}, {"ANU", "JFK"}, {"JFK", "ANU"}, {"ANU", "EZE"}, {"TIA", "ANU"}, {"AXA", "TIA"}, {"TIA", "JFK"}, {"ANU", "TIA"}, {"JFK", "TIA"} };
    Solution S;
    S.findItinerary(tickets);

    return 0;
}