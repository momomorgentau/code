//021
//*5
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int n,m;
vector<vector<int>> g,r;
vector<int> used;
vector<int> prm;
void dfs1(int a)
{
    used[a] = 1;
    for(auto e:g[a])
    {
        if(used[e] == -1)
        {
            dfs1(e);
        }
    }
    prm.emplace_back(a);
}
ll l = 0;
void dfs2(int a)
{

    used[a] = 1;
    ++l;
    for(auto e:r[a])
    {
        if(used[e] == -1)
        {
            dfs2(e);
        }
    }
}
int main()
{
    cin >> n >> m;
    g.resize(n);
    r.resize(n);
    used.resize(n,-1);
    rep(i,m)
    {
        int a,b;cin >> a >> b;
        --a,--b;
        g[a].emplace_back(b);
        r[b].emplace_back(a);
    }
    rep(i,n)
    {
        if(used[i] == -1)
        {
            dfs1(i);
        }
    }
    rep(i,n) used[i] = -1;
    reverse(prm.begin(),prm.end());
    ll ans = 0;
    for(auto a:prm)
    {
        if(used[a] == -1)
        {
            l = 0;
            dfs2(a);
            ans += l * (l-1)/2;
        }
    }
    cout << ans << endl;
    return 0;
}