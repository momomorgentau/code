//93
//abc185_b_smartphone_addiction
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;


int main()
{
	ll n, m, t;
	cin >> n >> m >> t;
	ll mn = n;
	vector<ll> a(m), b(m);
	rep(i, m) cin >> a[i] >> b[i];
	bool ok = true;
	rep(i, m)
	{
		if (i == 0) n -= a[i];
		else n -= a[i] - b[i - 1];
		if (n <= 0) ok = false;
		n += b[i] - a[i];
		n = min(mn, n);
	}

	if (n - (t - b.back()) <= 0) ok = false;

	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}