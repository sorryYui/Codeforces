#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const long long mod = 1e9 + 7;
vector<vector<int>> map;
vector<long long> mask, dfsn, lown, st, cost;
set<long long> s;
long long mins, tot = 1, cnt;
void dfs(int, int);
int main(void)
{
	int n;
	cin >> n;
	map.resize(n + 1), mask.resize(n + 1), cost.resize(n + 1);
	dfsn.resize(n + 1), lown.resize(n + 1);
	for (int i = 1;i <= n;i++)
	{
		cin >> cost[i];
		mask[i] = false;
	}
	int m;
	cin >> m;
	for (int i = 0;i < m;i++)
	{
		int u, v;
		cin >> u >> v;
		map[u].push_back(v);
	}
	for (int i = 1;i <= n;i++)
		if (!mask[i])
			dfs(i, 0);
	cout << mins << " " << tot << endl;
	return 0;
}
void dfs(int cur, int pre)
{
	dfsn[cur] = lown[cur] = ++cnt;
	mask[cur] = true;
	st.push_back(cur), s.insert(cur);
	for (auto u : map[cur])
		if (!mask[u])
		{
			dfs(u, cur);
			lown[cur] = min(lown[cur], lown[u]);
		}
		else if (s.count(u))
			lown[cur] = min(lown[cur], dfsn[u]);
	if (dfsn[cur] == lown[cur])
	{
		long long curval = INT_MAX, kcnt = 0, curv;
		do
		{
			curv = st.back();
			st.pop_back(), s.erase(curv);
			if (curval == cost[curv])
				kcnt++;
			else if (curval > cost[curv])
				kcnt = 1, curval = cost[curv];
		} while (curv != cur);
		mins += curval, tot = tot * kcnt % mod;
	}
}
