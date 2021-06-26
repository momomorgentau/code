//ABC_204_E
//Rush_Hour_2
//1710
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, int>;
using T = tuple<int,int,int>;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<T>> g(n);
    rep(i, m)
    {
        ll a, b,c,d;
        cin >> a >> b >> c >> d;
        --a, --b;
        g[a].emplace_back(b, c, d);
        g[b].emplace_back(a, c, d);

    }

    const ll INF = 1e18;
    vector<ll> d(n, INF);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, 0);
    d[0] = 0;

    while (!pq.empty())
    {
        ll c = pq.top().first;
        int s = pq.top().second;
        pq.pop();
        if (d[s] < c) continue;
        for (const auto& gi: g[s])
        {
            int e, ci, di;
            tie(e, ci, di) = gi;
            int t = round(sqrt(di));
            ll next = d[s] + ci + di / max((ll)t, d[s] + 1) + max(0LL, t - 1 - d[s]);
            if (d[e] <= next) continue;
            d[e] = next;
            pq.emplace(d[e], e);
        }
    }
    ll ans = d[n - 1];

    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}

