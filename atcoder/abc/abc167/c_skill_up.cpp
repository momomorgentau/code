//446
//abc167c_skill_up

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

const int inf = 1e9;
int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n)
    {
        cin >> c[i];
        rep(j, m) cin >> a[i][j];
    };

    int ans = inf;
    rep(i, 1 << n)
    {
        vector<ll> s(m);
        int tc = 0;
        rep(j, n)
        {
            if (i & 1 << j)
            {
                tc += c[j];
                rep(k, m)
                {
                    s[k] += a[j][k];
                }
            }
        }
        //”»’è
        bool ok = true;
        rep(i, m)
        {
            if (s[i] < x)
            {
                ok = false;
                break;
            }
        }

        if (ok) ans = min(ans, tc);
    }

    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
