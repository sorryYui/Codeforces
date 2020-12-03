#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	long long n, m, b, mod;
	cin >> n >> m >> b >> mod;
	vector<long long> a(n + 1);
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	vector<vector<long long>> f(m + 1, vector<long long>(b + 1, 0));
	for (int i = 0;i <= b;i++)
		f[0][i] = 1LL % mod;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			for (int k = 0;k <= b;k++)
				if (k >= a[i])
					f[j][k] = (f[j][k] + f[j - 1][k - a[i]]) % mod;
	cout << f[m][b] << endl;
	return 0;
}
