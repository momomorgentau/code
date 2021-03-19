//ABC_187_E_Through_Path
//1358
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;
int main() 
{
    int n;
    cin >> n;
    vector<P> node(n-1);
    vector<vector<int>> edge(n);
    rep(i, n - 1)
    {
        int ai, bi;
        cin >> ai >> bi;
        --ai; --bi;
        node[i] = make_pair(ai, bi);
        edge[ai].emplace_back(bi);
        edge[bi].emplace_back(ai);
    }
    vector<int> dist(n, -1);
    dist[0] = 0;
    queue<int> d;
    d.emplace(0);
    while (!d.empty())
    {
        int te = d.front();
        d.pop();
        for (auto a : edge[te])
        {
            if (dist[a] != -1) continue;
            dist[a] = dist[te] + 1;
            d.emplace(a);
        }
    }

    int q; cin >> q;
    ll all = 0;
    vector<ll> score(n,0);
    rep(i, q)
    {
        int t, e, x;
        cin >> t >> e >> x;
        --e;
        int ai, bi;
        tie(ai, bi) = node[e];
        if (t == 1)
        {
            if (dist[ai] < dist[bi])
            {
                all += x;
                score[bi] -= x;
            }
            else
            {
                score[ai] += x;
            }
        }
        else
        {
            if (dist[ai] > dist[bi])
            {
                all += x;
                score[ai] -= x;
            }
            else
            {
                score[bi] += x;
            }
        }
    }


    const ll inf = -1e18;
    vector<ll> ans(n, inf);
    ans[0] = score[0];
    queue<int> que;
    que.emplace(0);
    while (!que.empty())
    {
        int te = que.front();
        que.pop();
        for (auto a : edge[te])
        {
            if (ans[a] != inf) continue;
            ans[a] = ans[te] + score[a];
            que.emplace(a);
        }
    }

    rep(i, n) cout << ans[i] + all << endl;

    return 0;
}