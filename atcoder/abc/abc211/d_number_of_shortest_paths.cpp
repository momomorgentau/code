//ABC_211_D
//Number_of_Shortest_paths
//755
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, int>;
using T = tuple<int, int, int>;

const int mod = 1e9 + 7;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    const int INF = 1e9;
    vector<P> d(n, make_pair(0, INF));
    queue<int> q;
    q.emplace(0);
    d[0] = make_pair(1, 0);
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        for (auto const& e : g[a])
        {
            if (d[e].second <= d[a].second) continue;

            if (d[e].second == INF)
            {
                q.emplace(e);
            }
            d[e].first += d[a].first;
            d[e].first %= mod;
            d[e].second = d[a].second + 1;

        }
    }
    cout << d[n - 1].first << endl;

    return 0;
}