//diff1246
//abc183_e_queen_on_grid

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;
using P = pair<int, int>;

const int mod = 1e9 + 7;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<bool>> g(h, vector<bool>(w));
    rep(i, h)rep(j, w)
    {
        char c; cin >> c;
        if (c == '#') g[i][j] = false;
        else g[i][j] = true;
    }
    vector<vector<ll>> dp(h, vector<ll>(w));
    vector<vector<ll>> row(h, vector<ll>(w));
    vector<vector<ll>> col(h, vector<ll>(w));
    vector<vector<ll>> dia(h, vector<ll>(w));

    dp[0][0] = 1;
    row[0][0] = 0;
    col[0][0] = 0;
    dia[0][0] = 0;

    rep(i, h)rep(j, w)
    {
        int x = j;
        int y = i;
        //‰¡•ûŒü
        int rx = x + 1;
        if (rx < w && g[y][rx])
        {
            row[y][rx] += row[y][x] + dp[y][x];
            row[y][rx] %= mod;
            dp[y][rx] += row[y][rx];
            dp[y][rx] %= mod;
        }
        //c•ûŒü
        int dy = y + 1;
        if (dy < h && g[dy][x])
        {
            col[dy][x] += col[y][x] + dp[y][x];
            col[dy][x] %= mod;
            dp[dy][x] += col[dy][x];
            dp[dy][x] %= mod;
        }
        //ŽÎ‚ß•ûŒü
        if (rx < w && dy < h && g[dy][rx])
        {
            dia[dy][rx] += dia[y][x] + dp[y][x];
            dia[dy][rx] %= mod;
            dp[dy][rx] += dia[dy][rx];
            dp[dy][rx] %= mod;
        }
    }

    cout << dp[h - 1][w - 1] << endl;
    return 0;
}

