#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int len, t;
	cin >> len >> t;
	string s, p;
	cin >> s >> p;
	int x = 0;
	t = len - t;
	for (int i = 0;i < len;i++)
		x += s[i] == p[i];
	if (len + x < 2 * t)
	{
		cout << -1 << endl;
		exit(0);
	}
	string ans;
	ans.resize(len);
	if (t <= x)
		for (int i = 0;i < len;i++)
			if (s[i] == p[i] && t)
				ans[i] = s[i], t--;
			else
			{
				char ch = 'a';
				while (ch == s[i] || ch == p[i])
					ch++;
				ans[i] = ch;
			}
	else
	{
		for (int i = 0;i < len;i++)
			ans[i] = s[i] == p[i] ? s[i] : 'A';
		int cnt = t - x;
		for (int i = 0;i < len;i++)
			if (cnt && ans[i] == 'A')
				ans[i] = s[i], cnt--;
		cnt = t - x;
		for (int i = 0;i < len;i++)
			if (cnt && ans[i] == 'A')
				ans[i] = p[i], cnt--;
		for (int i = 0;i < len;i++)
			if (ans[i] == 'A')
			{
				char ch = 'a';
				while (ch == s[i] || ch == p[i])
					ch++;
				ans[i] = ch;
			}
	}
	cout << ans << endl;
	return 0;
}
