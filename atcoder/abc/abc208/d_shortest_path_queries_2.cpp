//ABC_208_D
//Shortest Path Queries 2
//1190
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<int, int, int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    const int INF = 1e9;
    vector<vector<int>> dp(n, vector<int>(n, INF));
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        dp[a][b] = c;
    }
    rep(i, n) dp[i][i] = 0;
    ll ans = 0;
    rep(k, n)
    {
        rep(i, n)rep(j, n)
        {
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            if (dp[i][j] == INF) continue;
            ans += dp[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}