#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;


bool IsSimilar(string s, string t)
{
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != t[i])
			count++;
		if (count > 1)
			return false;
	}
	if (count == 0)
		return false;
	else
		return true;
}
// 使用广度优先遍历找到最短路径

void BFS(vector<list<string>> graph, int i, string beginStr)
{
	queue<string> que;
	que.push(beginStr);
	while (!que.empty())
	{

	}
}
int main()
{
	int n;
	cin >> n;
	string beginStr, endStr, str;
	cin >> beginStr >> endStr;
	unordered_set<string> strSet;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		strSet.insert(str);
	}
	// 记录strSet里的字符串是否被访问过，同时记录路径长度
	unordered_map<string, int> visitMap;	// <记录的字符串，路径长度>

	// 初始化队列
	queue<string> que;
	que.push(beginStr);

	// 初始化visitMap
	visitMap.insert(pair<string, int>(beginStr, 1));

	while (!que.empty())
	{
		string word = que.front();
		que.pop();
		int path = visitMap[word];		// 这个字符串在路径中的长度

		// 开始在这个str中，挨个字符去替换
		for (int i = 0; i < word.size(); i++)
		{
			string newWord = word;

			for (int j = 0; j < 26; j++)
			{
				newWord[i] = j + 'a';
				if (newWord == endStr)
				{
					// 找到了路径
					cout << path + 1 << endl;
					return 0;
				}
				// 字符串集合里面有且未访问过
				if (strSet.find(newWord) != strSet.end()
					&& visitMap.find(newWord) == visitMap.end())
				{
					visitMap.insert(pair<string, int>(newWord, path + 1));
					que.push(newWord);
				}
			}
		}
	}
	cout << 0 << endl;

	return 0;
}