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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);
        backtracking(candidates, target, 0, used);

        return ans;
    }
    /*
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
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            if (i > startIndex && candidates[i] == candidates[i - 1])
                continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, i + 1);
            path.pop_back();
            sum -= candidates[i];
        }
        return;
    }
    */
    // ���˸�BOOL����
    void backtracking(vector<int> candidates, int target, int startIndex, vector<bool>& used)
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
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            // used[i - 1] == true��˵��ͬһ��֦candidates[i - 1]ʹ�ù�
            // used[i - 1] == false��˵��ͬһ����candidates[i - 1]ʹ�ù�
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i-1] == false)
                continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, i + 1, used);
            used[i] = false;
            path.pop_back();
            sum -= candidates[i];
        }
        return;
    }
};

int main()
{
    vector<int> candidates = { 2,5,2,1,2 };
    int target = 5;

    Solution S;
    S.combinationSum2(candidates, target);

    return 0;
}