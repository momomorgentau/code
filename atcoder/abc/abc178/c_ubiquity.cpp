#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
const int mod = pow(10, 9) + 7;
int main()
{
	int n;
	cin >> n;
	ll a = 1, b = 1, d = 1;
	rep(i, n) {
		a = (a * 10) % mod;
		b = (b * 9) % mod;
		d = (d * 8) % mod;
	}
	ll ans = (a - 2 * b + d) % mod;
	if (ans < 0) ans += mod;

	cout << ans << endl;
	return 0;
}