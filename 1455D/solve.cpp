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
		int n, x;
		cin >> n >> x;
		vector<int> a(n + 1, -1);
		for (int i = 1;i <= n;i++)
			cin >> a[i];
		int ans = 0, error = 0;
		for (int i = 1;i <= n;i++)
			if (a[i] < a[i - 1])
			{
				for (int j = 1;j < i;j++)
					x < a[j] ? swap(x, a[j]), ans++ : x;
				error = a[i - 1] > a[i] ? 1 : error;
			}
		cout << (error ? -1 : ans) << endl;
	}
	return 0;
}
