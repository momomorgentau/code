//ABC_126_D_Even_Relation
//1279
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<vector<P>> e(n);
    rep(i, n-1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    vector<int> ans(n,-1);
    queue<int> q;
    q.emplace(0);
    ans[0] = 0;
    while (!q.empty())
    {
        int ui,ai;
        ui = q.front();
        q.pop();
        ai = ans[ui];
        for (auto ei : e[ui])
        {
            int vi, wi;
            tie(vi, wi) = ei;
            if (ans[vi] != -1) continue;
            if (wi & 1) ans[vi] = !ans[ui];
            else ans[vi] = ans[ui];
            q.emplace(vi);
        }
    }
    rep(i, n) cout << ans[i] << endl;
    return 0;
}