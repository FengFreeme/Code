#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int n = bills.size();
        unordered_map<int, int> umap;
        umap[5] = 0;
        umap[10] = 0;
        for (int i = 0; i < n; i++)
        {
            if (bills[i] == 5)
            {
                umap[5]++;
            }
            else if (bills[i] == 10)
            {
                if (umap[5] >= 1)
                {
                    umap[5]--;
                    umap[10]++;
                }
                else
                    return false;
            }
            else if (bills[i] == 20) 
            {
                if (umap[5] >= 1 && umap[10] >= 1)
                {
                    umap[5]--;
                    umap[10]--;
                }
                else if (umap[5] >= 3)
                {
                    umap[5] = umap[5] - 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> bills = { 5,5,10,10,20 };

    Solution S;
    S.lemonadeChange(bills);

    return 0;
}