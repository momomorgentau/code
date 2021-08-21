//ABC_209_D
//Collision
//686
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;


int main()
{
    int n, Q;
    cin >> n >> Q;
    vector<vector<int>> g(n);
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);

    }
    vector<int> d(n, -1);
    d[0] = 0;
    queue<P> q;
    q.emplace(0, 1);
    while (!q.empty())
    {
        int e, di;
        tie(e, di) = q.front();
        q.pop();
        for (auto ei : g[e])
        {
            if (d[ei] != -1) continue;
            d[ei] = di;
            q.emplace(ei, di + 1);
        }
    }
    while (Q--)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (abs(d[y] - d[x]) % 2 == 0)cout << "Town" << endl;
        else cout << "Road" << endl;
    }


    return 0;
}