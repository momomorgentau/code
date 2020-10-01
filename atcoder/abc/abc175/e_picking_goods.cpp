#include<bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll = long long;

int v[3000][3000];
ll dp[3000][3000][4];
int main() {

    int R, C, K;
    cin >> R >> C >> K;

    rep(i, K) {
        int r, c, a;
        cin >> r >> c >> a;
        v[r - 1][c - 1] = a;
    }

    dp[0][0][1] = v[0][0];
    rep(r, R)rep(c, C)rep(k, 4) {
        if (r + 1 < R) {//c‚É“®‚­
          //E‚í‚È‚¢
            dp[r + 1][c][0] = max(dp[r + 1][c][0], dp[r][c][k]);
            //E‚¤
            dp[r + 1][c][1]
                = max(dp[r + 1][c][1], dp[r][c][k] + v[r + 1][c]);
        }
        if (c + 1 < C) { //‰¡‚É“®‚­
          //E‚í‚È‚¢
            dp[r][c + 1][k] = max(dp[r][c + 1][k], dp[r][c][k]);
            //E‚¤
            if (k + 1 <= 3) {
                dp[r][c + 1][k + 1]
                    = max(dp[r][c + 1][k + 1], dp[r][c][k] + v[r][c + 1]);
            }
        }
    }

    ll ans = 0;
    rep(i, 4) ans = max(ans, dp[R - 1][C - 1][i]);
    cout << ans << endl;
    return 0;
}