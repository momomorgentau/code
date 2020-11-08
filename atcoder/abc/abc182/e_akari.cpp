//1056
//abc182e_akari

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;
using P = pair<int, int>;

int main()
{
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<vector<bool>> roomh(h, vector<bool>(w));
    vector<vector<bool>> roomw(h, vector<bool>(w));

    vector<P> li;
    //•Ç‚ÌˆÊ’u‚ð‹tˆø‚«
    vector<vector<int>> wh(h);
    vector<vector<int>> ww(w);

    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        --a; --b;
        li.emplace_back(a, b);
    }
    rep(i, m)
    {
        int c, d;
        cin >> c >> d;
        --c; --d;
        wh[c].emplace_back(d);
        ww[d].emplace_back(c);
    }
    //‰¡•ûŒü
    rep(i, n)
    {
        int a, b;
        a = li[i].first;
        b = li[i].second;
        if (roomh[a][b]) continue;
        vector<int> tw = wh[a];
        sort(tw.begin(), tw.end());
        int l = 0;
        int r = w - 1;
        for (auto ttw : tw)
        {
            if (ttw < b) l = ttw + 1;
            if (b < ttw)
            {
                r = ttw - 1;
                break;
            }
        }
        reps(j, l, r + 1) roomh[a][j] = true;
    }
    //c•ûŒü
    rep(i, n)
    {
        int a, b;
        a = li[i].first;
        b = li[i].second;
        if (roomw[a][b]) continue;
        vector<int> tw = ww[b];
        sort(tw.begin(), tw.end());
        int s = 0;
        int t = h - 1;
        for (auto ttw : tw)
        {
            if (ttw < a) s = ttw + 1;
            if (a < ttw)
            {
                t = ttw - 1;
                break;
            }
        }

        reps(j, s, t + 1) roomw[j][b] = true;
    }
    int ans = 0;
    rep(i, h)rep(j, w)
    {
        if (roomh[i][j] || roomw[i][j]) ++ans;
    }

    cout << ans << endl;

    return 0;
}

