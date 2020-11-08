#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(void)
{
	int level[26];
	for (int i = 0;i < 26;i++)
		cin >> level[i];
	string s;
	cin >> s;
	long long ans = 0;
	for (char ch = 'a';ch <= 'z';ch++)
	{
		map<long long, long long> m;
		long long sum = 0;
		for (int i = 0;i < s.length();i++)
		{
			sum += level[s[i] - 'a'];
			if (s[i] == ch)
				ans += m[sum - level[ch - 'a']], m[sum]++;
		}
	}
	cout << ans << endl;
	return 0;
}
