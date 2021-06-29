//078
//Easy Graph Problem
//*2
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;


int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m)
    {
        int a, b; cin >> a >> b;
        --a, --b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int ans = 0;
    rep(i, n)
    {
        int now = 0;
        for (auto e : g[i])
        {
            if (i > e) ++now;
        }
        if (now == 1) ++ans;
    }
    cout << ans << endl;
    return 0;
}