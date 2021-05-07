//032
//*3
//ex N<=18
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
void chmin(int& a, int b) { a = min(a, b); };

const int N = 18;
const int N2 = 1 << N;
int dp[N2 + 5][N + 5];

int main()
{
	int n, m;
	cin >> n;
	vector<vector<int>> cost(n, vector<int>(n));
	vector<vector<int>> vor(n, vector<int>(n));
	rep(i, n)rep(j, n)cin >> cost[i][j];
	cin >> m;
	rep(i, m)
	{
		int x, y; cin >> x >> y;
		--x; --y;
		vor[x][y] = 1;
		vor[y][x] = 1;
	}
	const int INF = 1e9;
	rep(i, N2)rep(j, N) dp[i][j] = INF;
	rep(i, n) dp[1 << i][i] = cost[i][0];

	reps(i, 1, n)
	{
		rep(bit, (1 << n))
		{
			int cnt = 0;
			rep(j, n) if ((bit >> j) & 1) ++cnt;
			if (cnt != i) continue;
			rep(last, n)
			{
				rep(add, n)
				{
					if (bit & (1 << add)) continue;
					if (vor[last][add]) continue;
					chmin(dp[bit | (1 << add)][add], dp[bit][last] + cost[add][i]);
				}
			}
		}
	}
	int ans = INF;
	rep(i, n) chmin(ans, dp[(1 << n) - 1][i]);
	if (ans == INF) ans = -1;
	cout << ans << endl;


	return 0;
}