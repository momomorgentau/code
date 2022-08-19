//Educational DP Contest L
//Deque
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    const ll INF = 1e18;
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<ll>> dp(n, vector<ll>(n));
    int even = (n + 1) % 2;

    rep(i, n)reps(j, i, n)
    {
        dp[i][j] = ((even ^ ((j - i) % 2)) ? 1 : -1) * INF;
    }
    rep(i, n) dp[i][i] = a[i] * (even ? -1 : 1);
    reps(i, 1, n)
    {
        rep(l, n)
        {
            int r = l + i;
            if (r >= n) break;
            // 先手：数を大きくするように選ぶ
            if ((n - i) % 2)
            {
                dp[l][r] = max(dp[l][r - 1] + a[r], dp[l + 1][r] + a[l]);
            }
            //後手：数を小さくするように選ぶ
            else
            {
                dp[l][r] = min(dp[l][r - 1] - a[r], dp[l + 1][r] - a[l]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}