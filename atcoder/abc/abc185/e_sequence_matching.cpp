//1468
//abc185_e_sequence_matching
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

const int inf = 1e9;

void chmin(int& a, int b) { a = min(a, b); }

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, inf));
	dp[0][0] = 0;

	rep(i, n + 1)rep(j, m + 1)
	{
		if (i < n) chmin(dp[i + 1][j], dp[i][j] + 1);
		if (j < m) chmin(dp[i][j + 1], dp[i][j] + 1);
		if (i < n && j < m)
		{
			if (a[i] == b[j]) chmin(dp[i + 1][j + 1], dp[i][j]);
			else chmin(dp[i + 1][j + 1], dp[i][j] + 1);
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}