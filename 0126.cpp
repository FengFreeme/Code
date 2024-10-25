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
        for (const string& w : wordList)        //dict����wordList�г�beginWord��endWord����Ĵ�
            dict.insert(w);                     //���������򼯺ϱȽϷ��㣬����ʹ�ø�������
        if (!dict.count(endWord))
            return ans;
        dict.erase(beginWord);
        dict.erase(endWord);
        unordered_set<string> q1{ beginWord }, q2{ endWord };       //���ڽ��й�����ȱ���
        unordered_map<string, vector<string>> next;                 //���浥�ʵ�����������һ���ڽӵ��� ӳ�䱣��
        bool reversed = false, found = false;
        //������ȱ���
        while (!q1.empty())
        {
            unordered_set<string> q;        //��������ʱ���е����ã�
            for (const string& w : q1)
            {
                string s = w;       //��ʱ���������浥��
                for (size_t i = 0; i < s.size(); i++)     //�޷������� ѭ�� �ó����ʵ������ڽӵ���
                {
                    char ch = s[i];
                    for (int j = 0; j < 26; j++)
                    {
                        s[i] = j + 'a';         //�ı�����һ����ĸ
                        if (q2.count(s))        //����ҵ�Ŀ�굥��
                        {
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            found = true;
                        }
                        if (dict.count(s))      //��������ڵ��ʱ���
                        {
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            q.insert(s);        //��� ����Ѱ���¸����ʵ��ڽӵ���
                        }
                    }
                    s[i] = ch;                  //�ظ�
                }
            }
            if (found)
                break;
            for (const string& w : q)           //����ӵ�Ԫ������
                dict.erase(w);
            if (q.size() <= q2.size())
                q1 = q;                         //������һ��Ҫ�����ĵ��ʶ���
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
    //���ݣ��ؽ����п���·��
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