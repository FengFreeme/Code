#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int startX = 0, startY = 0;     //����ÿѭ��һ��Ȧ����ʼλ��
        int loop = n / 2;               //ÿ��Ȧѭ������
        int mid = n / 2;                //�����м�λ��
        int count = 1;                  //������ÿһ���ո�ֵ
        int offset = 1;                 //����ÿһ���߱����ĳ���
        int i, j;
        while (loop--)
        {
            i = startX;
            j = startY;

            //����
            for (j; j < n - offset; j++)
                ans[i][j] = count++;
            for (i; i < n - offset; i++)
                ans[i][j] = count++;
            for (j; j > startX; j--)
                ans[i][j] = count++;
            for (i; i > startX; i--)
                ans[i][j] = count++;

            //��ѭ����ʼλ��Ҫ+1
            startX++;
            startY++;

            offset++;
        }
        // nΪ���� ������ֵ
        if (n % 2)
            ans[mid][mid] = count;

        return ans;
    }
};