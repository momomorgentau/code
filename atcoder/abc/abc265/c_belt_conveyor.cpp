//----------------------------
//ABC 265 C
//Belt Conveyor
//212
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    rep(i, h) cin >> g[i];
    int x = 0;
    int y = 0;
    vector<vector<int>> used(h, vector<int>(w, -1));
    used[y][x] = 1;
    while (1)
    {
        int dx = 0;
        int dy = 0;
        if (g[y][x] == 'U') dy = -1;
        if (g[y][x] == 'D') dy = 1;
        if (g[y][x] == 'L') dx = -1;
        if (g[y][x] == 'R') dx = 1;
        x += dx;
        y += dy;
        if (x < 0 || w <= x || y < 0 || h <= y)
        {
            cout << y - dy + 1 << " " << x - dx + 1 << endl;
            return 0;
        }
        if (used[y][x] == 1)
        {
            cout << -1 << endl;
            return 0;
        }
        used[y][x] = 1;
    }
    return 0;
}