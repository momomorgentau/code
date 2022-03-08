//----------------------------
//ABC 242 C
//1111gal password
//512
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

const int MOD = 998244353;
int main()
{
	int n;
	cin >> n;
	vector<ll> dp(9, 1);
	rep(i, n - 1)
	{
		vector<ll> t = dp;
		rep(j, 9)
		{
			for (int k = -1; k <= 1; k += 2)
			{
				int nj = j + k;
				if (nj < 0 || 9 <= nj) continue;
				t[nj] += dp[j];
				t[nj] %= MOD;
			}
		}
		swap(t, dp);
	}

	ll ans = 0;
	for (const auto& a : dp)
	{
		ans += a;
		ans %= MOD;
	}
	cout << ans << endl;

}