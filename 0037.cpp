#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        backtracking(board);
    }
    // 1. 确定参数
    bool backtracking(vector<vector<char>>& board)
    {
        // 2. 确定终止条件
        // 如果最后一个不是'.'那么也就不会等于9，所以用这个作为判断条件不合适（不会进入递归，rowIndex无法等于9）
        /*
        if (rowIndex == 9)
            return true;
        */
        // 3. 单次递归处理
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char num = '1'; num <= '9'; num++)
                    {
                        /*
                        if (isValid(board, num, i, j))
                        {
                            board[i][j] = num;
                            if (j < 8)
                            {
                                if (backtracking(board, i, j + 1))
                                    return true;
                            }
                            else
                            {
                                if (backtracking(board, i + 1, 0))
                                    return true;
                            }
                            board[i][j] = '.';
                        }
                        */
                        if (isValid(board, num, i, j))
                        {
                            board[i][j] = num;
                            if (backtracking(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    // 9个数都试完了，无解，返回false，返回上一层递归直到找到解
                    return false;
                }
            }
        }
        // 遍历完没有返回false，说明成功了
        return true;
    }
    // 判断所要放置的数字是否合法
    bool isValid(vector<vector<char>> board, char num, int rowIndex, int colIndex)
    {
        // 首先分析行列规则
        // 判断行
        for (int j = 0; j < 9; j++)
        {
            if (board[rowIndex][j] == num)
                return false;
        }
        // 判断列
        for (int i = 0; i < 9; i++)
        {
            if (board[i][colIndex] == num)
                return false;
        }
        // 判断小九宫格
        int rowLimit = (rowIndex / 3) * 3;
        int colLimit = (colIndex / 3) * 3;
        for (int i = rowLimit; i < rowLimit + 3; i++)
        {
            for (int j = colLimit; j < colLimit + 3; j++)
            {
                if (board[i][j] == num)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> board = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };

    Solution S;
    S.solveSudoku(board);

    return 0;
}