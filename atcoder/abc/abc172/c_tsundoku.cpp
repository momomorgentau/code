//diff 878
//abc172_C_tsundoku

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll = long long;
using Pii = pair<int, int>;


int main()
{
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    ll cnt = 0;
    ll t = 0;
    int ai = -1;
    int bi = -1;

    rep(i, n)
    {
        ll tt = t + a[i];
        if (tt > k) break;
        t = tt;
        ++cnt;
        ai = i;
    }

    rep(i, m)
    {
        ll tt = t + b[i];

        if (tt > k) break;
        t = tt;
        ++cnt;
        bi = i;
    }

    ll ans = cnt;
    bool end = false;
    while (1)
    {
        if (ai > -1)
        {
            t -= a[ai];
            --ai;
            --cnt;
        }

        end = true;

        while (bi < m - 1)
        {
            ll tt = t;
            tt += b[bi + 1];
            if (tt <= k)
            {
                t = tt;
                ++bi;
                ++cnt;
                ans = max(ans, cnt);
                end = false;
            }
            else break;
        }

        if (ai == -1 && end) break;

    }

    cout << ans << endl;

    return 0;
}
