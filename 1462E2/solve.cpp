#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long mod = 1e9 + 7;
vector<long long> A(2e5 + 1);
long long f_pow(long long, long long);
long long c(long long, long long);
int main(void)
{
	A[0] = 1;
	for (long long i = 1;i <= 2e5;i++)
		A[i] = A[i - 1] * i % mod;
	int t;
	cin >> t;
	while (t--)
	{
		long long n, m, k;
		cin >> n >> m >> k;
		vector<long long> a(n);
		for (auto& u : a)
			cin >> u;
		sort(a.begin(), a.end());
		long long ans = 0, left = 0, right = 0;
		while (right < n)
		{
			while (left < right && a[left] < a[right] - k)
				left++;
			ans = (ans + c(right - left, m - 1)) % mod;
			right++;
			//cout << right << " " << left << endl;
		}
		cout << ans << endl;
	}
	return 0;
}
long long c(long long n, long long m)
{
	return n < m ? 0LL : A[n] * f_pow(A[m] * A[n - m] % mod, mod - 2);
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
