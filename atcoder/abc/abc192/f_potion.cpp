//ABC_192_F_Potion
//1783
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
void chmax(ll & x, ll y) { x = max(x, y); };

ll dp[105][105][105];

int main()
{
	int n;
    ll x;
	cin >> n >> x;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	const ll inf = 1e18;
	ll ans = inf;

	//ki個調合する時を考える
	for (int ki = 1; ki <= n; ++ki)
	{
		//初期化
		rep(i, n + 1)rep(j, n + 1)rep(m, n+1) dp[i][j][m] = -inf;
		dp[0][0][0] = 0;
	
		//i番目の素材を見ている
		for (int i = 0; i < n; ++i)
		{
			//現在 j個の素材を使っている（j <= ki かつ j <= i）
			for (int j = 0; j <= ki; ++j)
			{
				//m 余るときの値
				for (int m = 0; m < ki; ++m)
				{
					if (dp[i][j][m] == -inf) continue;
				    //a[i]の素材を選択しないとき
					chmax(dp[i + 1][j][m], dp[i][j][m]);

					//a[i]の素材を選択するとき(もし現在 j == kiなら行わない)
                    chmax(dp[i + 1][j+1][(m+a[i]) % ki], dp[i][j][m]+a[i]);
				}
			}
		}
		ll s = dp[n][ki][x % ki];
		if (s != -inf) ans = min(ans, (x - s) / ki);
	}
	cout << ans << endl;
	return 0;
}