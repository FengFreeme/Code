#include <iostream>
#include <vector>
#include <string>

using namespace std;
//自己写的
class Solution 
{
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int m = board.size(), n = board[0].size();
        if (m == 0 || n == 0)
            return false;
        int count;
        bool flag = false;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    count = 1;
                    char c = board[i][j];
                    board[i][j] = ' ';
                    DFS(board, word, count, i, j, flag);
                    if (count == word.size())
                        return true;
                    board[i][j] = c;
                }
            }
        }
        return false;
    }
    void DFS(vector<vector<char>>& board, string word, int& count, int r, int c, bool& flag)
    {
        if (count == word.size())
        {
            flag = true;
            return;
        }
            
        for (int i = 0; i < direction.size() - 1; i++)
        {
            int x = r + direction[i], y = c + direction[i + 1];
            if (x >= 0 && x < board.size() &&
                y >= 0 && y < board[0].size() && board[x][y] == word[count])
            {
                char c = board[x][y];
                board[x][y] = ' ';
                count++;
                DFS(board, word, count, x, y, flag);
                if (!flag)
                {
                    count--;
                    board[x][y] = c;
                }    
            }
        }
    }
private:
    vector<int> direction = { -1,0,1,0,-1 };
};
//按书上方法
class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        if (board.empty())
            return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool find = false;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                backtracking(i, j, board, word, find, visited, 0);
        }
        return find;
    }
    void backtracking(int i, int j, vector<vector<char>>& board, string& word, bool& find, vector<vector<bool>>& visited, int pos)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
        if (visited[i][j] || find || board[i][j] != word[pos])
            return;
        if (pos == word.size() - 1)
        {
            find = true;
            return;
        }
        visited[i][j] = true;       //修改当前节点状态
        backtracking(i + 1, j, board, word, find, visited, pos + 1);
        backtracking(i - 1, j, board, word, find, visited, pos + 1);
        backtracking(i, j + 1, board, word, find, visited, pos + 1);
        backtracking(i, j - 1, board, word, find, visited, pos + 1);
        visited[i][j] = false;      //回改当前节点状态
    }
private:
    vector<int> direction = { -1,0,1,0,-1 };
};

int main()
{
    vector<vector<char>> board = { {'a', 'a'} };
    string word = "aaa";

    Solution S;
    S.exist(board, word);

    return 0;
}