#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n, left, right;
		cin >> n >> left >> right;
		vector<long long> cnt(n + 2, 0);
		for (int i = 1;i <= n;i++)
			cnt[i] = 2 * (n - i);
		cnt[1]--, cnt[n]++, cnt[n + 1]++;
		vector<long long> pre(n + 2);
		for (int i = 1;i <= n + 1;i++)
			pre[i] = pre[i - 1] + cnt[i];
		long long curval = 0, val = 0, mod = 0;
		while (curval + cnt[val] < left)
			curval += cnt[val++];
		long long npos = left - curval - 1;
		vector<long long> ans;
		if (val > 1)
			ans.push_back(val == n + 1 ? 1 : n), curval++;
		while (curval < right)
		{
			if (curval == pre[val])
				mod = 0, ans.push_back(val == n ? 1 : n), val++;
			else
				ans.push_back(mod % 2 == 0 ? val : mod / 2 + val + 1), mod++;
			curval++;
		}
		while (npos < ans.size())
			cout << ans[npos++] << " ";
		cout << endl;
	}
	return 0;
}
