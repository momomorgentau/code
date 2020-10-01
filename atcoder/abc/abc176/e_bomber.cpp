#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> bh(h);
    vector<int> bw(w);

    set<P> b;

    rep(k, m) {
        int i, j;
        cin >> i >> j;
        --i, --j;
        ++bh[i], ++bw[j];
        b.emplace(i, j);
    }

    int max_w = 0;
    int max_h = 0;

    rep(i, h) max_h = max(max_h, bh[i]);
    rep(i, w) max_w = max(max_w, bw[i]);

    vector<int> mh;
    vector<int> mw;

    rep(i, h) {
        if (max_h == bh[i]) mh.emplace_back(i);
    }
    rep(i, w) {
        if (max_w == bw[i]) mw.emplace_back(i);
    }

    int ans = max_w + max_h;
    rep(i, mh.size()) {
        P mp;
        mp.first = mh[i];

        rep(j, mw.size()) {
            mp.second = mw[j];
            //Ç‡Çµê›íuèÍèäÇ…îöíeÇ™Ç†ÇÍÇŒcontinue
            if (b.count(mp)) continue;
            cout << ans << endl;
            return 0;
        }
    }

    cout << ans - 1 << endl;
    return 0;
}