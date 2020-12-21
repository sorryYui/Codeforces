#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> a(n + 1);
		for (int i = 1;i <= n;i++)
			cin >> a[i];
		vector<pair<double, double>> b(m + 1);
		for (int i = 1;i <= m;i++)
			cin >> b[i].first >> b[i].second;
		int npos = 0;
		for (int i = n;i > 0;i--)
			if (a[i] != i)
			{
				npos = i;
				break;
			}
		if (!npos)
		{
			cout << fixed << setprecision(7) << 1.0 << endl;
			continue;
		}
		double ans = 1;
		for (auto p : b)
			if (p.first >= npos)
				ans *= 1.0 - p.second;
		cout << fixed << setprecision(7) << 1.0 - ans << endl;
	}
	return 0;
}
