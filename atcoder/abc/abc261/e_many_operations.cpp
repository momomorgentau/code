//----------------------------
//ABC 261 E
//Many Operations
//1261
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
	ll n, c;
	cin >> n >> c;
	vector<vector<ll>> bit(2, vector<ll>(32, 0));
	rep(i, 32) bit[1][i] = 1;
	rep(i, n)
	{
		int t, a; cin >> t >> a;
		ll ans = 0;
		rep(i, 32) ans += (bit[(c >> i) & 1][i] << i);
		if (t == 1)
		{
			ans &= a;
			rep(i, 2)rep(j, 32)
			{
				bit[i][j] = ((a >> j) & 1) & bit[i][j];
			}
		}
		else if (t == 2)
		{
			ans |= a;
			rep(i, 2)rep(j, 32)
			{
				bit[i][j] = ((a >> j) & 1) | bit[i][j];
			}
		}
		else if (t == 3)
		{
			ans ^= a;
			rep(i, 2)rep(j, 32)
			{
				bit[i][j] = ((a >> j) & 1) ^ bit[i][j];
			}
		}
		printf("%d\n", ans);
		c = ans;
	}
	return 0;
}