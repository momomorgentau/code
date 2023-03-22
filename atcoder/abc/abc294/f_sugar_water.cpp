//----------------------------
// ABC 294 F
// Sugar Water
// 1891
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	ll n, m, k;
	cin >> n >> m >> k;
	vector<double> a(n), b(n);
	vector<double> c(m), d(m);
	rep(i, n) cin >> a[i] >> b[i];
	rep(i, m) cin >> c[i] >> d[i];

	double ac = 0;
	double wa = 100;
	int count = 100;
	while (count--)
	{
		double wj = (ac + wa) / 2;
		vector<double> v(m);
		rep(j, m) v[j] = c[j] - d[j] * wj / (100 - wj);
		sort(v.begin(), v.end());
		ll now = 0;
		rep(i, n)
		{
			double ai = a[i];
			double bi = b[i];
			double u = bi * wj / (100 - wj);

			now += m - (ll)(lower_bound(v.begin(), v.end(), -(ai - u)) - v.begin());
		}
		if (now >= k) ac = wj;
		else wa = wj;
	}
	printf("%.10f\n", ac);
	return 0;
}