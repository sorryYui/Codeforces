#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const long long mod = 1e9 + 7;
long long f_pow(long long, long long);
bool check(const string&, int, int);
int main(void)
{
	long long a, b, n;
	cin >> a >> b >> n;
	vector<long long> A(n + 1);
	A[0] = 1;
	for (long long i = 1;i <= n;i++)
		A[i] = A[i - 1] * i % mod;
	long long x = 0, ans = 0;
	while (max(a, b) * n >= min(a, b) * n + (max(a, b) - min(a, b)) * x)
	{
		long long val = min(a, b) * n + (max(a, b) - min(a, b)) * x;
		if (check(to_string(val), a, b))
			ans = (ans + A[n] * f_pow(A[x] * A[n - x] % mod, mod - 2) % mod) % mod;
		x++;
	}
	cout << ans << endl;
	return 0;
}
long long f_pow(long long x, long long r)
{
	if (!r)
		return 1LL;
	long long ret = f_pow(x, r / 2);
	ret = ret * ret % mod;
	ret = r & 1 ? ret * x % mod : ret;
	return ret;
}
bool check(const string& s, int a, int b)
{
	//cout << s << endl;
	for (auto ch : s)
		if (ch != a + '0' && ch != b + '0')
			return false;
	return true;
}
