#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int n, m;
	cin >> n >> m;
	string s1, s2;
	cin >> s1 >> s2;
	s1 = " " + s1, s2 = " " + s2;
	vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
	int maxlen = 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
		{
			f[i][j] = s1[i] == s2[j] ? f[i - 1][j - 1] + 2 : max(max(f[i][j - 1], f[i - 1][j]) - 1, 0);
			maxlen = max(f[i][j], maxlen);
		}
	cout << maxlen << endl;
	return 0;
}
