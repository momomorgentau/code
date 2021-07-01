//080
//Let's Share Bit
//*6
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int n, d;
    cin >> n >> d;
    int N = 1 << n;
    vector<vector<ll>> dp(d + 1, vector<ll>(N + 5));

    vector<ll> a(n), b(d);
    rep(i, n) cin >> a[i];
    rep(i, n)rep(j, d) b[j] |= ((a[i] >> j) & 1) << i;

    dp[0][0] = 1;
    rep(i, d)
    {
        rep(bit, 1 << n)
        {
            dp[i + 1][bit] += dp[i][bit];
            dp[i + 1][bit | b[i]] += dp[i][bit];
        }
    }
    cout << dp[d][(1 << n) - 1] << endl;
    return 0;
}
