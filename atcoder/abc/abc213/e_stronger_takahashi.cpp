//ABC_213_E
//Stronger Takahashi
//1423
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    rep(i, h) cin >> g[i];
    vector<int> dx0 = { 0,0,-1,1 };
    vector<int> dy0 = { 1,-1,0,0 };
    vector<int> dx1 = { -1,0,1,-2,-1,0,1,2,-2,-1,1,2,-2,-1,0,1,2,-1,0,1 };
    vector<int> dy1 = { 2,2,2,1,1,1,1,1,0,0,0,0,-1,-1,-1,-1,-1,-2,-2,-2 };

    deque<T> dq;
    dq.emplace_back(0, 0, 0);
    const int INF = 1e9;
    vector<vector<int>> d(h, vector<int>(w, INF));
    while (!dq.empty())
    {
        int ex, ey, c;
        tie(ex, ey, c) = dq.front();
        dq.pop_front();

        rep(i, 4)
        {
            int nx = ex + dx0[i];
            int ny = ey + dy0[i];
            if (nx < 0 || h <= nx) continue;
            if (ny < 0 || w <= ny) continue;
            if (g[nx][ny] == '#') continue;
            if (d[nx][ny] <= c) continue;
            d[nx][ny] = c;
            dq.emplace_front(nx, ny, c);
        }

        rep(i, 20)
        {
            int nx = ex + dx1[i];
            int ny = ey + dy1[i];
            if (nx < 0 || h <= nx) continue;
            if (ny < 0 || w <= ny) continue;
            if (d[nx][ny] <= c + 1) continue;
            d[nx][ny] = c + 1;
            dq.emplace_back(nx, ny, c + 1);
        }
    }
    cout << d[h - 1][w - 1] << endl;
    return 0;
}