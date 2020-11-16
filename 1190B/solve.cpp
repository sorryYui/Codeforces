#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	vector<long long> a(n);
	for (auto& u : a)
		cin >> u;
	map<long long, int> m;
	int cnt = 0, win = 1, fir = 0;
	long long sum = 0;
	for (int i = 0;i < n;i++)
		m[a[i]]++, sum += a[i];
	set<long long> s;
	for (int i = 0;i < n;i++)
		if (!s.count(a[i]))
			cnt += m[a[i]] == 2, win = m[a[i]] > 2 ? 0 : win, s.insert(a[i]);
	win = cnt > 1 ? 0 : win;
	for (int i = 0;i < n;i++)
		if (m[a[i]] == 2)
		{
			win = a[i] == 0 ? 0 : win, fir = 1;
			sum--, m[a[i]]--, m[a[i] - 1]++;
			win = m[a[i] - 1] > 1 ? 0 : win;
			break;
		}
	for (int i = 0;i < n;i++)
		sum -= i;
	//cout << fir << " " << win << " " << sum << endl;
	if (fir)
		cout << (win && sum % 2 == 0? "sjfnb" : "cslnb") << endl;
	else
		cout << (win && sum % 2 ? "sjfnb" : "cslnb") << endl;
	return 0;
}
