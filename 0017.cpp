#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    unordered_map<char, string> umap;
    
    vector<string> ans;
    string path;
    vector<string> letterCombinations(string digits) 
    {
        umap['2'] = "abc";
        umap['3'] = "def";
        umap['4'] = "ghi";
        umap['5'] = "jkl";
        umap['6'] = "mno";
        umap['7'] = "pqrs";
        umap['8'] = "tuv";
        umap['9'] = "wxyz";
        if (digits == "")
            return ans;
        backtracking(digits, 0);

        return ans;
    }
    /*
    // startIndex代表当前使用的数字
    void backtracking(string digits, string alpha, int startIndex)
    {
        if (path.size() == digits.size())
        {
            ans.push_back(path);
            return;
        }
        if (startIndex >= digits.size())
            return;
        for (int i = 0; i < alpha.size(); i++)
        {
            path.push_back(alpha[i]);
            backtracking(digits, umap[digits[startIndex + 1]], startIndex + 1);
            path.pop_back();
        }
    }
    */
    // startIndex代表当前使用的数字
    void backtracking(string digits, int startIndex)
    {
        if (path.size() == digits.size())
        {
            ans.push_back(path);
            return;
        }
        if (startIndex >= digits.size())
            return;
        string alpha = umap[digits[startIndex]];
        for (int i = 0; i < alpha.size(); i++)
        {
            path.push_back(alpha[i]);
            backtracking(digits, startIndex + 1);
            path.pop_back();
        }
    }
};

int main()
{
    string digits = "23";
    Solution S;
    S.letterCombinations(digits);

    return 0;
}