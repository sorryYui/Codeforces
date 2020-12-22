#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long c(long long);
int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& u : a)
			cin >> u;
		sort(a.begin(), a.end());
		int left = 0, right = 0;
		long long ans = 0;
		while (right < n)
		{
			while (left < right && a[left] < a[right] - 2)
				left++;
			ans += c(1LL * right - 1LL * left);
			right++;
		}
		cout << ans << endl;
	}
	return 0;
}
long long c(long long n)
{
	return n < 2 ? 0 : n * (n - 1) / 2;
}
