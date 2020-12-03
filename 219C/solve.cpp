#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
void print(const vector<vector<int>>&, const string&, string&, int, int);
int main(void)
{
	cin >> n >> m;
	string s, str = "";
	cin >> s;
	s = " " + s;
	vector<vector<int>> f(n + 1, vector<int>(m, n + 1));
	for (int i = 0;i < m;i++)
		f[0][i] = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j < m;j++)
			for (int k = 0;k < m;k++)
				if (j != k)
					f[i][j] = s[i] == j + 'A' ? min(f[i][j], f[i - 1][k]) : min(f[i][j], f[i - 1][k] + 1);
	int ans = n + 1, pos = 0;
	for (int i = 0;i < m;i++)
		if (ans > f[n][i])
			ans = f[n][i], pos = i;
	str += 'A' + pos;
	print(f, s, str, n - 1, pos);
	cout << ans << endl;
	for (int i = str.length() - 1;i >= 0;i--)
		cout << str[i];
	return 0;
}
void print(const vector<vector<int>>& f, const string& src, string& s, int setp, int pos)
{
	if (!setp)
		return;
	for (int i = 0;i < m;i++)		
		if ((f[setp][i] == f[setp + 1][pos] && src[setp + 1] == 'A' + pos && i != pos) || 
			(f[setp][i] == f[setp + 1][pos] - 1 && src[setp + 1] != 'A' + pos && i != pos))
		{
			s += 'A' + i;
			print(f, src, s, setp - 1, i);
			break;
		}
}
