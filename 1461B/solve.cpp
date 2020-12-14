#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<char>> map(n + 1, vector<char>(m + 1));
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				cin >> map[i][j];
		vector<vector<long long>> up(n + 1, vector<long long>(m + 2, 0));
		vector<vector<long long>> pre(n + 1, vector<long long>(m + 2, 0));
		vector<vector<long long>> suf(n + 1, vector<long long>(m + 2, 0));
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
			{
				up[i][j] = map[i][j] == '*' ? up[i - 1][j] + 1 : 0;
				pre[i][j] = min(pre[i][j - 1] + 1, up[i][j]);
			}
		for (int i = 1;i <= n;i++)
			for (int j = m;j > 0;j--)
				suf[i][j] = min(suf[i][j + 1] + 1, up[i][j]);
		long long tot = 0;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				tot += min(pre[i][j], suf[i][j]);
		cout << tot << endl;
	}
	return 0;
}
