#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long mod = 998244353;
long long f_pow(long long, long long);
int main(void)
{
	long long n;
	cin >> n;
	vector<long long> p(2 * n + 1);
	for (int i = 1;i <= 2 * n;i++)
		cin >> p[i];
	sort(p.begin() + 1, p.end());
	vector<long long> a(2 * n + 1);
	a[0] = 1;
	for (long long i = 1;i <= 2 * n;i++)
		a[i] = a[i - 1] * i % mod;
	long long sum = 0;
	for (int i = 1;i <= 2 * n;i++)
		sum = i <= n ? (sum - p[i] + mod) % mod: (sum + p[i]) % mod;
	long long ans = sum * (a[2 * n] * f_pow(a[n] * a[n] % mod, mod - 2) % mod) % mod;
	cout << ans << endl;
	return 0;
}
long long f_pow(long long a, long long r)
{
	if (!r)
		return 1LL;
	long long ret = f_pow(a, r / 2);
	ret = ret * ret % mod;
	ret = r & 1 ? ret * a % mod : ret;
	return ret;
}
