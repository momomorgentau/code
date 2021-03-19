//ABC_192_E_Train
//1135
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
const ll inf = 1e18;

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    --x, --y;
    vector<vector<T>> edge(n, vector<T>());
    rep(i, m)
    {
        ll a, b, t, k;
        cin >> a >> b >> t >> k;
        --a, --b;
        edge[a].emplace_back(b, t, k);
        edge[b].emplace_back(a, t, k);
    }

    vector<ll> d(n, inf);
    priority_queue<P, vector<P>, greater<P>> pq;

    d[x] = 0;
    pq.emplace(0, x);

    while (!pq.empty())
    {
        ll c = pq.top().first;
        int s = pq.top().second;
        pq.pop();

        //cout << c <<endl;
        if (d[s] < c) continue;
        for (auto a : edge[s])
        {
            ll gt = get<0>(a);
            ll gc = get<1>(a);
            ll gk = get<2>(a); // 待ち時間
            ll gw = gk - c % gk;
            if (gw == gk) gw = 0;
            if (d[gt] <= d[s] + gc + gw) continue;
            d[gt] = d[s] + gc + gw;
            pq.emplace(d[gt], gt);
        }
    }
    ll ans = d[y];
    if (ans == inf) ans = -1;
    cout << ans << endl;

    return 0;
}