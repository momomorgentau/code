//diff 2367
//abc180_f_unbranched
#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,s,n) for(int i=s;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int mod = 1e9 + 7;

int f(int n, int m, int l)
{
	//種類数の計算
	vector<int> path(l + 1, 0), cycle(l + 1, 0);
	path[1] = 1;

	if (l >= 2) path[2] = 1; // l=1のとき対策
	reps(i, 3, l + 1) path[i] = ((ll)path[i - 1] * i) % mod;
	reps(i, 2, l + 1) cycle[i] = path[i - 1];

	//頂点の選び方の計算
	//パスカルの三角形を用いる
	vector<vector<int>> p(n + 1, vector<int>(n + 1));
	p[0][0] = 1;
	rep(i, n)rep(j, i + 1)
	{
		p[i + 1][j] += p[i][j];
		p[i + 1][j] %= mod;

		p[i + 1][j + 1] += p[i][j];
		p[i + 1][j + 1] %= mod;
	}
	//dpテーブル
	//dp[i][j]: i個頂点を使った。j個辺を使った。
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	dp[0][0] = 1;
	//dpを回す
	rep(i, n)rep(j, m + 1)
		//追加辺 j が0でも、頂点だけ追加できるのでjはmまで、
	{
		//pathの追加
		reps(k, 1, l + 1)
		{
			int ni = k + i;
			int nj = k + j - 1;
			if (ni > n || nj > m) break;
			/*
			一気に掛けるとオーバフローするので都度modを取る
			やっていることは
			dp[ni][nj] += dp[i][j] * cycle[k]* p[n - i - 1][k - 1] % mod;
			dp[ni][nj] %= mod;
			*/
			ll add = ((ll)path[k] * p[n - i - 1][k - 1]) % mod;
			add = (add * dp[i][j]) % mod;
			dp[ni][nj] = (dp[ni][nj] + add) % mod;

		}
		//cycleの追加
		reps(k, 2, l + 1)
		{
			int ni = k + i;
			int nj = k + j;
			if (ni > n || nj > m) break;
			/*
			一気に掛けるとオーバフローするので都度modを取る
			やっていることは
			dp[ni][nj] += dp[i][j] * path[k]* p[n - i - 1][k - 1] % mod;
			dp[ni][nj] %= mod;
			*/
			ll add = ((ll)cycle[k] * p[n - i - 1][k - 1]) % mod;
			add = (add * dp[i][j]) % mod;
			dp[ni][nj] = (dp[ni][nj] + add) % mod;
		}
	}
	return dp[n][m];
}

int main()
{
	int n, m, l;
	cin >> n >> m >> l;

	int ans = f(n, m, l) - f(n, m, l - 1);
	if (ans < 0) ans += mod;
	else ans %= mod;
	cout << ans << endl;

	return 0;
}