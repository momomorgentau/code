#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll = long long;
int main()
{
	ll n, d;
	cin >> n >> d;
	vector<ll> x(n);
	vector<ll> y(n);

	rep(i, n) cin >> x[i] >> y[i];

	int cnt = 0;
	rep(i, n) {
		if (x[i] * x[i] + y[i] * y[i] <= d * d) cnt++;
	}
	cout << cnt;

	return 0;
}