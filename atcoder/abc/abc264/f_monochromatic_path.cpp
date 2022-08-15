//----------------------------
//ABC 264 F
//Monochromatic Path
//1878
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int H = 2000;
const int W = 2000;
ll dp[H][W][2][2];
int main()
{
	int h, w;
	cin >> h >> w;
	vector<ll> r(h), c(w);
	rep(i, h) cin >> r[i];
	rep(i, w) cin >> c[i];
	vector<vector<int>> a(h, vector<int>(w));
	rep(i, h)
	{
		string s; cin >> s;
		rep(j, w) a[i][j] = s[j] - '0';
	}
	const ll INF = 1e18;
	ll ans = INF;
	rep(color, 2)
	{

		rep(i, h)rep(j, w)rep(y, 2)rep(x, 2) dp[i][j][y][x] = INF;

		if (a[0][0] == color)
		{
			dp[0][0][0][0] = 0;
			dp[0][0][1][1] = r[0] + c[0];
		}
		else
		{
			dp[0][0][1][0] = r[0];
			dp[0][0][0][1] = c[0];
		}

		rep(i, h)rep(j, w)rep(y, 2)rep(x, 2)
		{
			if (i + 1 < h)
			{
				int nc = a[i + 1][j] ^ x;
				if (nc == color) dp[i + 1][j][0][x] = min(dp[i][j][y][x], dp[i + 1][j][0][x]);
				else dp[i + 1][j][1][x] = min(dp[i][j][y][x] + r[i + 1], dp[i + 1][j][1][x]);
			}
			if (j + 1 < w)
			{
				int nc = a[i][j + 1] ^ y;
				if (nc == color) dp[i][j + 1][y][0] = min(dp[i][j][y][x], dp[i][j + 1][y][0]);
				else dp[i][j + 1][y][1] = min(dp[i][j][y][x] + c[j + 1], dp[i][j + 1][y][1]);
			}
		}
		rep(y, 2)rep(x, 2) ans = min(dp[h - 1][w - 1][y][x], ans);
	}
	cout << ans << endl;
	return 0;
}
