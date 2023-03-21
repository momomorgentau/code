//----------------------------
// ABC 294 E
// 2*N Grid
// 792
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	ll l, n1, n2;
	cin >> l >> n1 >> n2;
	vector<ll> v1(n1), t1(n1), v2(n2), t2(n2);
	rep(i, n1) cin >> v1[i] >> t1[i];
	rep(i, n2) cin >> v2[i] >> t2[i];

	ll l1 = 0, r1 = t1[0];
	ll l2 = 0, r2 = t2[0];
	ll idx1 = 0; ll idx2 = 0;
	ll ans = 0;
	while (idx1 < n1 && idx2 < n2)
	{
		if (v1[idx1] == v2[idx2])
		{
			ll s1 = r1 - l1;
			ll s2 = r2 - l2;
			ll lmx = max(l1, l2);
			ll rmn = min(r1, r2);
			ll add = max(rmn - lmx, 0LL);

			ans += add;
		}
		if (idx1 == n1 - 1 && idx2 == n2 - 1)
		{
			break;
		}
		if (r1 <= r2)
		{
			++idx1;
			l1 = r1;
			r1 += t1[idx1];
		}
		else
		{
			++idx2;
			l2 = r2;
			r2 += t2[idx2];
		}

	}
	cout << ans << endl;
	return 0;
}

