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
		int n;
		cin >> n;
		vector<vector<int>> map(n, vector<int>(n));
		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
			{
				char ch;
				cin >> ch;
				map[i][j] = ch - '0';
			}
		vector <vector<pair<int, int>>> v(10);
		vector<int> maxr(10, -1), minr(10, INT_MAX), maxc(10, -1), minc(10, INT_MAX);
		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
			{
				v[map[i][j]].push_back(make_pair(i, j));
				maxr[map[i][j]] = max(maxr[map[i][j]], i), maxc[map[i][j]] = max(maxc[map[i][j]], j);
				minr[map[i][j]] = min(minr[map[i][j]], i), minc[map[i][j]] = min(minc[map[i][j]], j);
			}
		vector<int> maxs(10, 0);
		for (int i = 0;i < 10;i++)
			for (auto p : v[i])
			{
				int a = max(n - 1 - p.first, p.first), h1 = max(maxc[i] - p.second, p.second - minc[i]);
				int b = max(n - 1 - p.second, p.second), h2 = max(maxr[i] - p.first, p.first - minr[i]);
				maxs[i] = max(maxs[i], max(a * h1, b * h2));
			}
		for (int i = 0;i < 10;i++)
			cout << maxs[i] << " ";
		cout << endl;
	}
	return 0;
}
