#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int n, m;
	cin >> n >> m;
	bool mask = false;
	vector<vector<int>> tmp(max(n, m) + 1, vector<int>(max(n, m) + 1));
	vector<vector<int>> map(max(n, m) + 1, vector<int>(max(n, m) + 1));
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> tmp[i][j];
	map = tmp;
	if (n > m)
	{
		mask = true;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				map[j][i] = tmp[i][j];
		swap(n, m);
	}
	vector<int> minR(n + 1, INT_MAX), minC(m + 1, INT_MAX);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			minR[i] = min(minR[i], map[i][j]);
	for (int i = 1;i <= m;i++)
		for (int j = 1;j <= n;j++)
			minC[i] = min(minC[i], map[j][i] - minR[j]);
	bool error = false;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			error = minR[i] + minC[j] == map[i][j] ? error : true;
	if (error)
	{
		cout << -1 << endl;
		exit(0);
	}
	int cnt = 0;
	for (int i = 1;i <= n;i++)
		cnt += minR[i];
	for (int i = 1;i <= m;i++)
		cnt += minC[i];
	cout << cnt << endl;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j < minR[i];j++)
			cout << (mask ? "col " : "row ") << i << endl;
	for (int i = 1;i <= m;i++)
		for (int j = 0;j < minC[i];j++)
			cout << (mask ? "row " : "col ") << i << endl;
	return 0;
}
