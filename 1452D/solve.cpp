#include <iostream>
#include <vector>
using namespace std;
const long long mod = 998244353;
long long f_pow(long long, long long);
int main(void)
{
	long long n;
	cin >> n;
	vector<long long> f(n + 1), g(n + 1);
	f[0] = 0, f[1] = g[0] = 1, g[1] = 2;
	for (int i = 2;i <= n;i++)
	{
		f[i] = (f[i - 1] + f[i - 2]) % mod;
		g[i] = g[i - 1] * 2 % mod;
	}
	long long ans = f[n] * f_pow(g[n], mod - 2) % mod;
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
