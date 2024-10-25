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
// ʹ�ù�����ȱ����ҵ����·��

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
	// ��¼strSet����ַ����Ƿ񱻷��ʹ���ͬʱ��¼·������
	unordered_map<string, int> visitMap;	// <��¼���ַ�����·������>

	// ��ʼ������
	queue<string> que;
	que.push(beginStr);

	// ��ʼ��visitMap
	visitMap.insert(pair<string, int>(beginStr, 1));

	while (!que.empty())
	{
		string word = que.front();
		que.pop();
		int path = visitMap[word];		// ����ַ�����·���еĳ���

		// ��ʼ�����str�У������ַ�ȥ�滻
		for (int i = 0; i < word.size(); i++)
		{
			string newWord = word;

			for (int j = 0; j < 26; j++)
			{
				newWord[i] = j + 'a';
				if (newWord == endStr)
				{
					// �ҵ���·��
					cout << path + 1 << endl;
					return 0;
				}
				// �ַ���������������δ���ʹ�
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