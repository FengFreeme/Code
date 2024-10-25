#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    int sum = 0;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);

        return ans;
    }
    // ���Ǽ�֦�Ż�
    // 1. ȷ�������ͷ��ز���
    void backtracking(vector<int> candidates, int target, int startIndex)
    {
        // 2. ��ֹ����
        if (sum == target)
        {
            ans.push_back(path);
            return;
        }
        else if (sum > target)
            return;
        // 3. ���εݹ鴦��
        // ������for�������£�ֱ���˳�ѭ��
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, i);        // ����i+1�ˣ���ʾ�����ظ���ȡ��ǰ����
            path.pop_back();
            sum -= candidates[i];
        }
        return;
    }
};

int main()
{
    vector<int> candidates = { 2,3,5 };
    int target = 8;

    Solution S;
    S.combinationSum(candidates, target);

    return 0;
}