#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution 
{
public:
    int candy(vector<int>& ratings) 
    {
        vector<int> candy = vector<int>(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1] && candy[i] <= candy[i - 1])
                candy[i] = candy[i - 1] + 1;
            else if (ratings[i] < ratings[i - 1] && candy[i] >= candy[i - 1])
                candy[i - 1] = candy[i] + 1;
        }
        for (int i = ratings.size() - 1; i >= 1; i--)
        {
            if (ratings[i] > ratings[i - 1] && candy[i] <= candy[i - 1])
                candy[i] = candy[i - 1] + 1;
            else if (ratings[i] < ratings[i - 1] && candy[i] >= candy[i - 1])
                candy[i - 1] = candy[i] + 1;
        }
        int ans = 0;
        for (int i = 0; i < candy.size(); i++)
        {
            ans += candy[i];
        }
        return ans;
    }
};

int main()
{
    vector<int> ratings = { 1,2,87,87,87,2,1 };
    Solution S;
    cout << S.candy(ratings) << endl;

    return 0;
}