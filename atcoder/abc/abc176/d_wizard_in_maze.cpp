#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int h, w, sh, sw, th, tw;
    cin >> h >> w >> sh >> sw >> th >> tw;
    --sh; --sw; --th; --tw;
    vector<string> s(h);
    //入力がh行のstring 
    rep(i, h) cin >> s[i];

    vector<vector<int>> dist(h, vector<int>(w, INT_MAX));

    deque<P> q;

    vector<int> mx = { 0, 0, -1, 1 };
    vector<int> my = { 1, -1, 0, 0 };

    dist[sh][sw] = 0;
    q.emplace_back(sh, sw);
    while (!q.empty()) {
        int i = q[0].first;
        int j = q[0].second;
        int d = dist[i][j];
        q.pop_front();
        //歩きでの移動
        rep(k, 4) {
            int ni = i + mx[k];
            int nj = j + my[k];
            //枠外に飛び出さないかの判定
            if (ni < 0 || h - 1 < ni || nj < 0 || w - 1 < nj) continue;
            //壁かの判定
            if (s[ni][nj] == '#') continue;
            //更新可能、到達済みかの判定
            if (dist[ni][nj] <= d) continue;
            dist[ni][nj] = d;
            q.emplace_front(ni, nj);
        }
        //魔法での移動
        for (int wx = -2; wx <= 2; ++wx) {
            for (int wy = -2; wy <= 2; ++wy) {
                int ni = i + wx;
                int nj = j + wy;
                //枠外に飛び出さないかの判定
                if (ni < 0 || h - 1 < ni || nj < 0 || w - 1 < nj) continue;
                //壁かの判定
                if (s[ni][nj] == '#') continue;
                //更新可能、到達済みかの判定
                if (dist[ni][nj] <= d + 1) continue;
                dist[ni][nj] = d + 1;
                q.emplace_back(ni, nj);
            }
        }
    }

    int ans = dist[th][tw];
    if (ans == INT_MAX) ans = -1;

    cout << ans << endl;

    return 0;
}