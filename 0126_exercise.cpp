#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        vector<vector<string>> ans;
        unordered_set<string> dict;
        for (const string& w : wordList)
            dict.insert(w);
        if (!dict.count(endWord))
            return ans;
        dict.erase(beginWord);
        dict.erase(endWord);
        unordered_set<string> q1{ beginWord }, q2{ endWord };
        unordered_map<string, vector<string>> next;
        //bool reversed = false;
        bool found = false;
        //从起点开始广度优先遍历
        while (!q1.empty())
        {
            unordered_set<string> q;
            for (const string& w : q1)
            {
                string s = w;
                for (int i = 0; i < s.size(); i++)
                {
                    char c = s[i];
                    for (int j = 0; j < 26; j++)
                    {
                        s[i] = 'a' + j;         
                        if (q2.count(s))
                        {
                            //在这里s是单词的一个邻接单词
                            next[w].push_back(s);
                            found = true;
                        }
                        if (dict.count(s))
                        {
                            next[w].push_back(s);
                            q.insert(s);
                        }
                    }
                    s[i] = c;
                }
            }
            if (found)
                break;
            for (const string& w : q)
                dict.erase(w);
            /*
            if (q.size() <= q2.size())
                q1 = q;
            else
            {
                reversed = !reversed;
                q1 = q2;
                q2 = q;
            }
            */
            q1 = q;
        }
        if (found)
        {
            vector<string> path = { beginWord };
            backtracking(beginWord, endWord, next, path, ans);
        }
        return ans;
    }
    void backtracking(const string& src, string& dst, unordered_map<string, vector<string>> next, 
        vector<string>& path, vector<vector<string>>& ans)
    {
        if (src == dst)
        {
            ans.push_back(path);
            return;
        }
        for (const string& w : next[src])
        {
            path.push_back(w);
            backtracking(w, dst, next, path, ans);
            path.pop_back();
        }
    }
};