#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		long long x, y, k;
		cin >> x >> y >> k;
		if (max(abs(x), abs(y)) > k)
		{
			cout << -1 << endl;
			continue;
		}
		else if (x == y)
		{
			cout << ((k - x) % 2 == 0 ? k : k - 2) << endl;
			continue;
		}
		long long last = k - min(abs(x), abs(y)), pre = max(abs(x), abs(y)) - min(abs(x), abs(y));
		if ((last - pre) % 2)
			cout << (pre % 2 ? k - 1 : k - 2) << endl;
		else
			cout << (pre % 2 ? k - 1 : k) << endl;
	}
	return 0;
}
