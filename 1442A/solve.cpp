#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0;i < n;i++)
			cin >> a[i];
		int error = 0, minimum = a[0];
		for (int i = 1;i < n;i++)
		{
			minimum -= max(0, a[i - 1] - a[i]);
			error = minimum < 0 ? 1 : error;
		}
		cout << (error ? "NO" : "YES") << endl;
	}
	return 0;
}
