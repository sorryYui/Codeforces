#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	vector<long long> a(n);
	for (auto& u : a)
		cin >> u;
	sort(a.begin(), a.end(), greater<long long>());
	long long npos = 1, len = 0, sum = 0;
	while (npos < n)
	{
		if (a[npos] + 1 >= a[npos - 1])
			len ? (sum += len * a[npos], len = 0) : (len = a[npos]), npos += 2;
		else
			npos++;
	}
	cout << sum << endl;
	return 0;
}
