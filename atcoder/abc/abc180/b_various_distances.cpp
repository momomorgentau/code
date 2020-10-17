//diff 70
#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	int n;
	cin >> n;

	ll am = 0;
	double ae = 0;
	int ac = 0;
	rep(i, n)
	{
		ll x;
		cin >> x;
		x = abs(x);
		am += x;
		ae += x * x;
		ac = max(ac, (int)x);
	}
	ae = sqrt(ae);

	cout << setprecision(9) << fixed;
	cout << am << endl;
	cout << ae << endl;
	cout << ac << endl;
	return 0;
}