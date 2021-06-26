//ABC_202_E
//Count_Descendants
//1638
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int M = 2e5;

vector<vector<int>> g;
vector<vector<P>> query;
int used[M + 5];
int num[M + 5];
int ans[M + 5];
void dfs(int s,int depth)
{
    for (auto [qd, qi] : query[s])
    {
        ans[qi] = -num[qd];
    }
    for (auto a : g[s])
    {
        if (used[a] == 1) continue;
        used[a] = 1;
        dfs(a,depth+1);
    }
    ++num[depth];
    for (auto [qd, qi] : query[s])
    {
        ans[qi] += num[qd];
    }
}
int main()
{
    int n,q;
    cin >> n;
    g.resize(n);
    reps(i,1, n)
    {
        int p;cin >> p;
        --p;
        g[p].emplace_back(i);
        g[i].emplace_back(p);
    }
    cin >> q;
    query.resize(n);
    rep(i,q)
    { 
        int u, d; cin >> u >> d;
        --u;
        query[u].emplace_back(d,i);
    }
    used[0] = 1;
    dfs(0,0);

    rep(i, q) cout << ans[i] << endl;
    return 0;
}