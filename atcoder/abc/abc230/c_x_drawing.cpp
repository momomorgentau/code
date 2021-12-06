//----------------------------
//ABC_230_C
//X_Drawing
//566
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
	ll n, a, b, p, q, r, s;
	cin >> n >> a >> b >> p >> q >> r >> s;
	ll k1m, k1M, k2m, k2M;
	k1m = max(1 - a, 1 - b);
	k1M = min(n - a, n - b);
	k2m = max(1 - a, b - n);
	k2M = min(n - a, b - 1);
	for (ll x = p; x <= q; ++x)
	{
		for (ll y = r; y <= s; ++y)
		{
			bool black = false;
			ll k1 = x - a;
			if (k1 == y - b && k1m <= k1 && k1 <= k1M)
			{
				black = true;
			}
			ll k2 = x - a;
			if (x - a == -y + b && k2m <= k2 && k2 <= k2M)
			{
				black = true;
			}
			if (black) cout << "#";
			else cout << ".";
		}
		cout << endl;
	}

	return 0;
}