#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int n = numbers.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (numbers[i] + numbers[j] == target)
                return { i + 1, j + 1 };
            else if (numbers[i] + numbers[j] > target)
                j--;
            else if (numbers[i] + numbers[j] < target)
                i++;
        }
        return {};
    }
};

int main()
{
    vector<int> numbers = { 5, 25, 75 };
    int target = 100;
    Solution S;
    vector<int> ans = S.twoSum(numbers, target);
    cout << ans[0] << "," << ans[1] << endl;

    return 0;
}