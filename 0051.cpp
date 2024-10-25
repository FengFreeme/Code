#include <iostream>
#include <vector>

using namespace std;
//代码随想录 回溯

class Solution 
{
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);

        return ans;
    }
    void backtracking(int n, int row, vector<string>& chessboard)
    {
        if (row == n)
        {
            ans.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if(isValid(row, col, chessboard, n))
            {
                chessboard[row][col] = 'Q';
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.';
            }
        }
        return;
    }
    bool isValid(int row, int col, vector<string>& chessboard, int n)
    {
        for (int i = 0; i < row; i++)
        {
            // 这是一个剪枝
            if (chessboard[i][col] == 'Q')
                return false;

            // 检查45°是否有皇后
            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
                if (chessboard[i][j] == 'Q')
                    return false;
            // 检查135°
            for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
                if (chessboard[i][j] == 'Q')
                    return false;
        }
        return true;
    }
};

/*
* * * 自己写的 * * *
class Solution 
{
public:
    vector<vector<string>> ans;
    vector<string> path;
    vector<vector<string>> solveNQueens(int n) 
    {
        string s;
        vector<pair<int, int>> t;
        path = vector<string>(n, string(n, '.'));

        backtracking(n, 0, t);

        return ans;
    }
    // 1. 确定参数
    void backtracking(int n, int rowIndex, vector<pair<int, int>>& t)
    {
        // 2. 确定终止条件
        if (rowIndex == n)
        {
            ans.push_back(path);
            return;
        }
        // 3. 单次递归处理
        // 按行递归，纵向遍历
        // for是横向遍历
        for (int i = 0; i < n; i++)
        {
            if(isValid(n, rowIndex, i, t))
            {
                path[rowIndex][i] = 'Q';
                t.push_back({ rowIndex, i });
                backtracking(n, rowIndex + 1, t);
                t.pop_back();
                path[rowIndex][i] = '.';
            }
        }
    }
    // 判断是否可放置
    bool isValid(int n, int rowIndex, int columnIndex, vector<pair<int, int>>& t)
    {
        if (t.size() == 0)
            return true;
        for (int i = 0; i < t.size(); i++)
        {
            if (rowIndex == t[i].first || columnIndex == t[i].second)
                return false;
            // 左斜线 '/'
            for (int k = t[i].first, l = t[i].second; k < n && l >= 0; k++, l--)
            {
                if (rowIndex == k && columnIndex == l)
                    return false;
            }
            // 右斜线 '\'
            for (int k = t[i].first, l = t[i].second; k < n && l < n; k++, l++)
            {
                if (rowIndex == k && columnIndex == l)
                    return false;
            }
        }
        return true;
    }
};
*/
int main()
{
    int n = 4;

    Solution S;
    S.solveNQueens(n);

    return 0;
}