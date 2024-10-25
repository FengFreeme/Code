#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int startX = 0, startY = 0;     //定义每循环一个圈的起始位置
        int loop = n / 2;               //每个圈循环几次
        int mid = n / 2;                //矩阵中间位置
        int count = 1;                  //给矩阵每一个空格赋值
        int offset = 1;                 //控制每一条边遍历的长度
        int i, j;
        while (loop--)
        {
            i = startX;
            j = startY;

            //左到右
            for (j; j < n - offset; j++)
                ans[i][j] = count++;
            for (i; i < n - offset; i++)
                ans[i][j] = count++;
            for (j; j > startX; j--)
                ans[i][j] = count++;
            for (i; i > startX; i--)
                ans[i][j] = count++;

            //新循环起始位置要+1
            startX++;
            startY++;

            offset++;
        }
        // n为奇数 单独赋值
        if (n % 2)
            ans[mid][mid] = count;

        return ans;
    }
};