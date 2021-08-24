//ABC_215
//Coprime 2
//736
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

vector<int> v;
vector<int> ans;
ll n, m;

void dfs(ll now, int pos)
{
    ans.emplace_back(now);
    for (int i = pos; i < v.size(); ++i)
    {
        if (now * v[i] <= m)
        {
            dfs(now * v[i], i);
        }
        else break;
    }
    return;
}



int main()
{
    cin >> n >> m;
    set<int> s;
    for (ll i = 2; i <= m; ++i)
    {
        bool ok = true;
        for (ll j = 2; j * j <= i; ++j)
        {
            if (i % j != 0) continue;
            ok = false;
            break;
        }
        if (ok) s.emplace(i);
    }
    rep(i, n)
    {
        int a; cin >> a;
        s.erase(a);
        for (ll j = 2; j * j <= a; ++j)
        {
            if (a % j != 0)continue;
            s.erase(j);
            s.erase(a / j);
        }
    }

    for (auto it = s.begin(); it != s.end(); ++it)
    {
        v.emplace_back(*it);
    }
    dfs(1, 0);
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (auto const& a : ans)printf("%d\n", a);
    return 0;
}