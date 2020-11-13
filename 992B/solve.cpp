#include <iostream>
#include <vector>
using namespace std;
long long gcd(long long a, long long b);
int main(void)
{
	long long l, r, x, y;
	cin >> l >> r >> x >> y;
	long long v = x * y, ans = 0;
	vector<long long> p;
	for (long long i = 1LL;i * i <= y;i++)
		if (y % i == 0)
			if (i * i == y)
				p.push_back(i);
			else
				p.push_back(i), p.push_back(y / i);
	for (int i = 0;i < p.size();i++)
		for (int j = 0;j < p.size();j++)
			if (gcd(p[i], p[j]) == x && p[i] * p[j] == v
				&& min(p[i], p[j]) >= l && max(p[i], p[j]) <= r)
				ans++;
	cout << ans << endl;
	return 0;
}
long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}
