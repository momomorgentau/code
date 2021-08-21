//ABC_213_D
//Takahashi Tour
//710
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n;
vector<vector<int>> g;
vector<int> used;
vector<int> ans;

void dfs(int a)
{
    ans.emplace_back(a + 1);
    for (auto const& e : g[a])
    {
        if (used[e] != -1) continue;
        used[e] = 1;
        dfs(e);
        ans.emplace_back(a + 1);
    }

}

int main()
{
    cin >> n;
    g.resize(n);
    used.resize(n, -1);
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    rep(i, n)
    {
        sort(g[i].begin(), g[i].end());
    }
    used[0] = 1;
    dfs(0);
    for (auto const& a : ans) cout << a << " ";
    cout << endl;
    return 0;
}