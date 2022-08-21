//Educational DP Contest N
//Slimes
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    const ll INF = 1e18;
    vector<vector<ll>> dp(n, vector<ll>(n, INF));
    rep(i, n) dp[i][i] = 0;
    vector<ll> sum(n + 1);
    rep(i, n) sum[i + 1] = a[i] + sum[i];
    reps(i, 2, n + 1)
    {
        reps(j, 1, i)
        {
            int l = j;
            int r = i - j;
            rep(s, n)
            {
                int li = s + l - 1;
                int ri = s + l - 1 + r;
                if (ri >= n) break;
                dp[s][ri] = min(dp[s][li] + dp[li + 1][ri] + sum[ri + 1] - sum[s], dp[s][ri]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}