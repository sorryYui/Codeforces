#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
const long long mod = 998244353;
int main(void)
{
	int q;
	cin >> q;
	while (q--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> a(n), b(k);
		for (auto& u : a)
			cin >> u;
		for (auto& u : b)
			cin >> u;
		set<int> s;
		map<int, int> m;
		for (auto u : b)
			s.insert(u);
		for (int i = 0;i < n;i++)
			m[a[i]] = i;
		long long ans = 1;
		for (auto u : b)
		{
			int left = m[u] - 1, right = m[u] + 1;
			long long cnt = 0;
			cnt += left >= 0 && !s.count(a[left]);
			cnt += right < n && !s.count(a[right]);
			ans = ans * cnt % mod;
			s.erase(u);
		}
		cout << ans << endl;
	}
	return 0;
}
