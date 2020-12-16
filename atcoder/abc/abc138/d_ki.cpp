//920
//abc138_d_ki
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> e(n);
    rep(i, n - 1)
    {
        int x, y; cin >> x >> y;
        --x; --y;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }
    vector<int> ans(n, 0);
    rep(i, q)
    {
        int pi, xi; cin >> pi >> xi;
        --pi;
        ans[pi] += xi;
    }

    vector<bool> memo(n, false);
    memo[0] = true;
    queue<int> que;
    que.emplace(0);
    while (!que.empty())
    {
        int qi = que.front();
        que.pop();
        for (auto ei : e[qi])
        {
            if (memo[ei]) continue;
            ans[ei] += ans[qi];
            memo[ei] = true;
            que.emplace(ei);
        }
    }

    for (auto ai : ans) cout << ai << " ";
    cout << endl;

    return 0;
}
