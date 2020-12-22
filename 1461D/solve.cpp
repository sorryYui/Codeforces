#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
set<long long> s;
vector<long long> a, pre;
void dfs(int, int);
int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;
		s.clear();
		a.resize(n + 1), pre.resize(n + 1);
		for (int i = 1;i <= n;i++)
			cin >> a[i];
		a[0] = pre[0] = 0;
		sort(a.begin() + 1, a.end());
		for (int i = 1;i <= n;i++)
			pre[i] = pre[i - 1] + 1LL * a[i];
		dfs(1, n);
		while (q--)
		{
			long long sum;
			cin >> sum;
			cout << (s.count(sum) ? "YES" : "NO") << endl;
		}
	}
	return 0;
}
void dfs(int left, int right)
{
	if (left > right)
		return;
	s.insert(pre[right] - pre[left - 1]);
	long long mid = (a[right] + a[left]) / 2;
	int npos = upper_bound(a.begin() + left, a.begin() + right + 1, mid) - a.begin();
	//cout << left << " " << right << endl;
	if (npos <= right)
		dfs(left, npos - 1);
	dfs(npos, right);
}
