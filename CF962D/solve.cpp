#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	vector<long long> a(n);
	for (auto& u : a)
		cin >> u;
	map<long long, long long> m;
	long long kcnt = 1;
	for (long long i = 0;i < n;i++)
		if (m.find(a[i]) == m.end())
			m[a[i]] = kcnt++;
	vector<set<long long>> npos(kcnt + 1);
	for (long long i = 0;i < n;i++)
		npos[m[a[i]]].insert(i);
	set<long long> s;
	vector<long long> ans(n, 0);
	for (int i = 0;i < n;i++)
		if (npos[m[a[i]]].size() > 1)
			s.insert(a[i]);
	while (!s.empty())
	{
		set<long long> ::iterator it = s.begin();
		npos[m[*it]].erase(npos[m[*it]].begin());
		int last = *npos[m[*it]].begin();
		npos[m[*it]].erase(npos[m[*it]].begin());
		if (!m.count(2 * (*it)))
			m[2 * (*it)] = kcnt++, npos.push_back(set<long long>());
		npos[m[2 * (*it)]].insert(last);
		if (npos[m[2 * (*it)]].size() == 2)
			s.insert(2 * (*it));
		//cout << last << endl;
		if (npos[m[*it]].size() < 2)
			s.erase(it);
	}
	set<long long> mask;
	for (auto p : m)
		if (!mask.count(p.first) && npos[p.second].size() == 1)
			ans[*npos[p.second].begin()] = p.first, mask.insert(p.first);
	cout << mask.size() << endl;
	for (int i = 0;i < n;i++)
		if (ans[i])
			cout << ans[i] << " ";
	return 0;
}
