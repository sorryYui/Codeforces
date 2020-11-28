#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
string ans,a,b;
vector<bool> mask;
void dfs(int);
int main(void)
{
	cin>>a>>b;
	mask.resize(a.length());
	ans = "";
	if (a.length() < b.length())
	{
		sort(a.begin(),a.end(),greater<char>());
		cout << a <<endl;
		exit(0);
	}
	for (int i = 0;i < a.length();i++)
		mask[i] = false;
	for (int i = 0;i < b.length();i++)
	{
		int npos = 0;
		char ch = '9' + 10;
		for (int j = 0;j < a.length();j++)
			abs((int)ch - (int)b[i]) > abs((int)a[j] - (int)b[i]) && !mask[j] && a[j] <= b[i] ? 
				npos = j,ch = a[j] : npos;
		if (ch <= '9' && ch == b[i])
			ans += ch,mask[npos] = true;
		else if (ch <= '9' && b[i] != ch)
		{
			ans += ch,mask[npos] = true;
			break;
		}
		else
		{
			dfs(i);
			break;
		}
	}
	string tmp = "";
	for (int i = 0;i < a.length();i++)
		if (!mask[i])
			tmp += a[i];
	sort(tmp.begin(),tmp.end(),greater<char>());
	cout << ans + tmp <<endl;
	system("pause");
	return 0;
}
void dfs(int point)
{
	for (int i = 0;i < a.length();i++)
		if (a[i] == ans.back() && mask[i])
		{
			mask[i] = false;
			break;
		}
	ans.pop_back(),point--;
	int npos = 0;
	char ch = '9' + 10;
	for (int i = 0;i < a.length();i++)
		abs((int)ch - (int)b[point]) > abs((int)a[i] - (int)b[point]) && !mask[i] && a[i] < b[point] ? 
				npos = i,ch = a[i] : npos;
	if (ch <= '9')
	{
		ans += ch,mask[npos] = true;
		return;
	}
	else
		dfs(point);
}
