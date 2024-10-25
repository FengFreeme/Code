#include <iostream>
#include <vector>
#include <string>

using namespace std;

class solution
{
public:
	void SwitchString1(string s)
	{
		int size = s.size();
		string ans;
		for (int i = 0; i < size; i++)
		{
			if (s[i] <= '9' && s[i] >= '0')
			{
				ans = ans + "number";
			}
			else
				ans = ans + s[i];
		}
		cout << ans << endl;
	}
	// 双指针法 从后向前遍历
	void SwitchString(string s)
	{
		int size = s.size();
		int Number = 0;
		for (int i = 0; i < size; i++)
		{
			if (s[i] <= '9' && s[i] >= '0')
				Number++;
		}
		int New_Size = size - Number + Number * 6;
		s.resize(New_Size);
		int index = New_Size - 1;
		for (int i = size - 1; i >= 0; i--)
		{
			if (s[i] <= '9' && s[i] >= '0')
			{
				s[index--] = 'r';
				s[index--] = 'e';
				s[index--] = 'b';
				s[index--] = 'm';
				s[index--] = 'u';
				s[index--] = 'n';
			}
			else
				s[index--] = s[i];
		}
		cout << s;
	}
};

int main()
{
	string s;
	cin >> s;

	solution S;
	S.SwitchString(s);

	return 0;
}