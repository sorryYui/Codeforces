#include <iostream>
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
		vector<vector<int>> map(n, vector<int>(m));
		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++)
			{
				char ch;
				cin >> ch;
				map[i][j] = ch - '0';
			}
		vector<vector<pair<int,int>>> ans;
		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++)
				if (map[i][j])
				{
					int modi = i > 0 ? 1 : -1, modj = j < m - 1 ? 1 : -1;
					ans.push_back(vector<pair<int, int>>(3));
					ans.back()[0] = (make_pair(i, j)), ans.back()[1] = (make_pair(i, j + modj)), ans.back()[2] = (make_pair(i - modi, j));
					ans.push_back(vector<pair<int, int>>(3));
					ans.back()[0] = make_pair(i, j), ans.back()[1] = make_pair(i - modi, j), ans.back()[2] = make_pair(i - modi, j + modj);
					ans.push_back(vector<pair<int, int>>(3));
					ans.back()[0] = make_pair(i, j), ans.back()[1] = make_pair(i, j + modj), ans.back()[2] = make_pair(i - modi, j + modj);
				}
		std::printf("%d\n", ans.size());
		for (int i = 0;i < ans.size();i++)
			std::printf("%d %d %d %d %d %d\n", ans[i][0].first + 1, ans[i][0].second + 1, 
				ans[i][1].first + 1, ans[i][1].second + 1, ans[i][2].first + 1, ans[i][2].second + 1);
	}
	return 0;
}
