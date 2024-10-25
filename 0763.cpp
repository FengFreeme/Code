#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    vector<int> partitionLabels(string s) 
    {
        unordered_map<char, int> umap;
        for (int i = 0; i < s.size(); i++)
        {
            umap[s[i]] = i;
        }
        vector<int> ans;
        int startIndex = 0;
        int endIndex = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (umap[s[i]] > endIndex)
                endIndex = umap[s[i]];
            if (i == endIndex)
            {
                ans.push_back(endIndex - startIndex + 1);
                startIndex = endIndex + 1;
            }
        }
        return ans;
    }
};

int main()
{
    string s = "eccbbbbdec";
    Solution S;
    vector<int> ans = S.partitionLabels(s);

    return 0;
}