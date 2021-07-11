//63
//Monochromatic Subgrid
//*4
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
    vector<vector<int>> g(h, vector<int>(w));
    rep(i, h)rep(j, w) cin >> g[i][j];
    int ans = 0;
    reps(bit, 1, 1 << h)
    {
        vector<int> v;
        rep(i, h)
        {
            if ((bit >> i) & 1) v.emplace_back(i);
        }
        int sz = v.size();
        unordered_map<int, int> mp;
        rep(i, w)
        {
            bool ok = true;
            int pi = g[v[0]][i];
            for (auto& hi : v)
            {
                if (g[hi][i] != pi)
                {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            ++mp[pi];
        }
        int now = 0;
        for (auto& [key, val] : mp) now = max(now, val * sz);
        ans = max(now, ans);
    }
    cout << ans << endl;
    return 0;
}