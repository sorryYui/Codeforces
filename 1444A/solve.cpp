#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 1e5 + 1;
long long f_pow(long long, long long);
int main(void)
{
	vector<bool> mask(maxn, false);
	mask[1] = true;
	for (int i = 2;i < maxn;i++)
		if (!mask[i])
			for (int j = 2 * i;j < maxn;j += i)
				mask[j] = true;
	vector<long long> prime;
	for (int i = 1;i < maxn;i++)
		if (!mask[i])
			prime.push_back(i);
	int t;
	cin >> t;
	while (t--)
	{
		long long p, q;
		cin >> p >> q;
		if (p < q)
		{
			cout << p << endl;
			continue;
		}
		map<long long, long long> mq;
		long long ans = 0;
		for (int i = 0;i < prime.size();i++)
			while (q % prime[i] == 0)
				q /= prime[i], mq[prime[i]]++;
		if (q > 1) mq[q]++;
		for (auto& u : mq)
		{
			long long tmpp = p, cnt = 0;
			while (tmpp % u.first == 0)
				tmpp /= u.first, cnt++;
			ans = cnt >= u.second ? max(ans, p / f_pow(u.first, cnt - u.second + 1)) : max(ans, p);
		}
		cout << ans << endl;
	}
	return 0;
}
long long f_pow(long long a, long long r)
{
	if (!r)
		return 1LL;
	long long ret = f_pow(a, r / 2);
	ret *= ret;
	ret = r & 1 ? ret * a : ret;
	return ret;
}
