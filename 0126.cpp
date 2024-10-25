#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        vector<vector<string>> ans;
        unordered_set<string> dict;
        for (const string& w : wordList)        //dict保存wordList中除beginWord和endWord以外的词
            dict.insert(w);                     //保存在无序集合比较方便，可以使用各个方法
        if (!dict.count(endWord))
            return ans;
        dict.erase(beginWord);
        dict.erase(endWord);
        unordered_set<string> q1{ beginWord }, q2{ endWord };       //用于进行广度优先遍历
        unordered_map<string, vector<string>> next;                 //保存单词的所有满足下一个邻接单词 映射保存
        bool reversed = false, found = false;
        //广度优先遍历
        while (!q1.empty())
        {
            unordered_set<string> q;        //类似于临时队列的作用？
            for (const string& w : q1)
            {
                string s = w;       //临时变量，保存单词
                for (size_t i = 0; i < s.size(); i++)     //无符号整数 循环 得出单词的所有邻接单词
                {
                    char ch = s[i];
                    for (int j = 0; j < 26; j++)
                    {
                        s[i] = j + 'a';         //改变任意一个字母
                        if (q2.count(s))        //如果找到目标单词
                        {
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            found = true;
                        }
                        if (dict.count(s))      //如果存在于单词表中
                        {
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            q.insert(s);        //入队 继续寻找下个单词的邻接单词
                        }
                    }
                    s[i] = ch;                  //回改
                }
            }
            if (found)
                break;
            for (const string& w : q)           //将入队的元素移走
                dict.erase(w);
            if (q.size() <= q2.size())
                q1 = q;                         //保存下一个要搜索的单词队列
            else
            {
                reversed = !reversed;
                q1 = q2;
                q2 = q;
            }
        }
        if (found)
        {
            vector<string> path = { beginWord };
            backtracking(beginWord, endWord, next, path, ans);
        }
        return ans;
    }
    //回溯，重建所有可能路径
    void backtracking(const string& src, const string& dst, unordered_map<string, vector<string>>& next,
        vector<string>& path, vector<vector<string>> &ans)
    {
        if (src == dst)
        {
            ans.push_back(path);
            return;
        }
        for (const string& s : next[src])
        {
            path.push_back(s);
            backtracking(s, dst, next, path, ans);
            path.pop_back();
        }
    }
};

int main()
{
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };

    Solution S;
    S.findLadders(beginWord, endWord, wordList);

    return 0;
}