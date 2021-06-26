//ABC_204_C
//Tour
//629
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

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
    }

    ll ans = 0;
    rep(i, n)
    {
        vector<int> used(n, -1);
        queue<int> q;
        q.emplace(i);
        used[i] = 1;
        ++ans;
        while (!q.empty())
        {
            int s = q.front();
            q.pop();
            for (auto e : g[s])
            {
                if (used[e] == 1) continue;
                used[e] = 1;
                q.emplace(e);
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

