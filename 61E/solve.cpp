#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define low_bit(x) (x & (-x))
using namespace std;
const int maxn = 1e6 + 1;
int a[maxn], c[maxn];
void update(int, int);
int getSum(int);
int main(void)
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	vector<pair<int, int>> p(n + 1);
	for (int i = 1;i <= n;i++)
		p[i] = make_pair(a[i], i);
	sort(p.begin() + 1, p.end());
	for (int i = 1;i <= n;i++)
		a[p[i].second] = i;
	vector<int> pre(n + 1, 0), suf(n + 1, 0);
	for (int i = 1;i <= n;i++)
	{
		update(a[i], 1);
		pre[i] = getSum(n) - getSum(a[i]);
	}
	memset(c, 0, sizeof(c));
	for (int i = n;i > 0;i--)
	{
		update(a[i], 1);
		suf[i] = getSum(a[i] - 1);
	}
	long long ans = 0;
	for (int i = 1;i <= n;i++)
		ans += 1LL * pre[i] * suf[i];
	cout << ans << endl;
	return 0;
}
void update(int pos, int k)
{
	while (pos < maxn)
	{
		c[pos] += k;
		pos += low_bit(pos);
	}
}
int getSum(int pos)
{
	int ret = 0;
	while (pos)
	{
		ret += c[pos];
		pos -= low_bit(pos);
	}
	return ret;
}
