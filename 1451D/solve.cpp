#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		long long k, d;
		cin >> d >> k;
		double a = (long long)(d / sqrt(2) / k) * sqrt(2) * k;
		double r = a * a + 1.0 * k * k - 2.0 * a * k * cos(3.14159 * 3 / 4);
		cout << (r > 1.0 * d * d ? "Utkarsh" : "Ashish") << endl;
		
	}
	return 0;
}
