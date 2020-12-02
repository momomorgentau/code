//119
//arc109_a_hands

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

const int inf = 1e9;

//O(1)
void solve1() 
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    int ans = 1e9;
    if (a > b)
    {
        ans = (a - b - 1) * y + x;
        ans = min(ans, (a - b) * (2 * x) - x);
    }
    else
    {
        ans = (b - a) * y + x;
        ans = min(ans, (b - a) * (2 * x) + x);
    }
    cout << ans << endl;
}

//bfs?
//âΩÇ≈âÇØÇƒÇÈÇÃÇ©ÇÌÇ©ÇËÇ‹ÇπÇÒÅB
void solve2()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    --a, --b;
    vector<vector<int>> t(100, vector<int>(2, inf));
    t[a][0] = 0;
    queue<P> q;
    q.emplace(a, 0);
    vector<int> dy{ -1,1 };
    while (!q.empty())
    {
        int ts, tn;
        tie(ts, tn) = q.front();
        q.pop();
        //ècà⁄ìÆ
        rep(i, 2)
        {
            int ns = ts + dy[i];
            if (0 <= ns && ns <= 99)
            {
                if (t[ns][tn] > t[ts][tn] + y)
                {
                    t[ns][tn] = t[ts][tn] + y;
                    q.emplace(ns, tn);
                }
            }
        }

        int nn = (tn ^ 1);
        //â°Ç…à⁄ìÆ
        if (t[ts][nn] > t[ts][tn] + x)
        {
            t[ts][nn] = t[ts][tn] + x;
            q.emplace(ts, tn ^ 1);
        }
        //éŒÇﬂÇ…à⁄ìÆ
        int ns;
        if (tn == 0) ns = -1;
        else ns = 1;
        ns += ts;

        if (0 <= ns && ns <= 99)
        {
            if (t[ns][nn] > t[ts][tn] + x)
            {
                t[ns][nn] = t[ts][tn] + x;
                q.emplace(ns, nn);
            }
        }
    }
    cout << t[b][1] << endl;
    return 0;
}

//Dijkstra
void solve3()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    --a, --b;
    vector<vector<P>> g(200);
    rep(i, 200)
    {
        if ((i != 99) && (i != 199))
        {
            g[i].emplace_back(i + 1, y);
            g[i + 1].emplace_back(i, y);
        }
    }
    rep(i, 100)
    {
        g[i].emplace_back(i + 100, x);
        g[i + 100].emplace_back(i, x);
    }
    reps(i, 1, 100)
    {
        g[i].emplace_back(i + 99, x);
        g[i + 99].emplace_back(i, x);
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, a);
    vector<int> d(200, int(1e9));
    d[a] = 0;
    while (!pq.empty())
    {
        int c, s;
        tie(c, s) = pq.top();
        pq.pop();
        if (d[s] < c) continue;
        for (auto a : g[s])
        {
            int ns = a.first;
            int nc = a.second;
            if (d[ns] <= d[s] + nc) continue;
            d[ns] = d[s] + nc;
            pq.emplace(d[ns], ns);
        }
    }
    cout << d[b + 100] << endl;
    return 0;
}

int main()
{
    solve1();
    //solve2();
    //solve3();
    return 0;
}