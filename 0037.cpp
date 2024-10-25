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
    // 1. ȷ������
    bool backtracking(vector<vector<char>>& board)
    {
        // 2. ȷ����ֹ����
        // ������һ������'.'��ôҲ�Ͳ������9�������������Ϊ�ж����������ʣ��������ݹ飬rowIndex�޷�����9��
        /*
        if (rowIndex == 9)
            return true;
        */
        // 3. ���εݹ鴦��
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
                    // 9�����������ˣ��޽⣬����false��������һ��ݹ�ֱ���ҵ���
                    return false;
                }
            }
        }
        // ������û�з���false��˵���ɹ���
        return true;
    }
    // �ж���Ҫ���õ������Ƿ�Ϸ�
    bool isValid(vector<vector<char>> board, char num, int rowIndex, int colIndex)
    {
        // ���ȷ������й���
        // �ж���
        for (int j = 0; j < 9; j++)
        {
            if (board[rowIndex][j] == num)
                return false;
        }
        // �ж���
        for (int i = 0; i < 9; i++)
        {
            if (board[i][colIndex] == num)
                return false;
        }
        // �ж�С�Ź���
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