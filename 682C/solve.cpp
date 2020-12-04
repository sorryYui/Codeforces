#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> tree, e;
vector<long long> dis, sum, f;
int ans;
int sum_f(int, int);
void dfs(int, int);
int main(void)
{
	int n;
	cin >> n;
	tree.resize(n + 1), dis.resize(n + 1);
	sum.resize(n + 1), e.resize(n + 1), f.resize(n + 1);
	for (int i = 1;i <= n;i++)
		cin >> dis[i];
	for (int i = 1;i < n;i++)
	{
		int c, p;
		cin >> c >> p;
		tree[c].push_back(i + 1), tree[i + 1].push_back(c);
		e[c].push_back(p), e[i + 1].push_back(p);
	}
	f[0] = 0;
	sum_f(1, 0);
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}
int sum_f(int cur, int pre)
{
	sum[cur] = 1;
	for (auto u : tree[cur])
		if (u != pre)
			sum[cur] += sum_f(u, cur);
	return sum[cur];
}
void dfs(int cur, int pre)
{
	if (f[cur] > dis[cur])
	{
		ans += sum[cur];
		return;
	}
	for (int i = 0;i < tree[cur].size();i++)
		if (tree[cur][i] != pre)
		{
			f[tree[cur][i]] = max(f[cur] + 1LL * e[cur][i], 1LL * e[cur][i]);
			dfs(tree[cur][i], cur);
		}
}
