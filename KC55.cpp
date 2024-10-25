#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class solution
{
public:
	/*void ReverseRight(string& s, int n)
	{
		int size = s.size();
		if (size < n)
			n = size;
		int index = size - n;
		string t = s.substr(index, n);
		for (int i = index - 1; i >= 0; i--)
		{
			s[i + n] = s[i];
		}
		for (int i = 0; i < n; i++)
		{
			s[i] = t[i];
		}
		cout << s;
	}*/
	void ReverseRight(string& s, int n)
	{
		int size = s.size();
		if (size < n)
			n = size;
		int index = size - n;
		reverse(s.begin(), s.end());
		reverse(s.begin(), s.begin() + n);
		reverse(s.begin() + n, s.end());
		cout << s;
	}
};

int main()
{
	string s;
	int n;
	cin >> n >> s;
	
	solution S;
	S.ReverseRight(s, n);

	return 0;
}