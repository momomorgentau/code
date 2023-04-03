//----------------------------
// ABC 296 D
// M<=ab
// 999
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1e18;
ll solve1(ll n, ll m)
{
    ll ans = INF;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            ll now = i * j;
            if (now < m) continue;
            ans = min(ans, now);
        }
    }
    if (ans == INF) ans = -1;
    return ans;
}

ll solve2(ll n, ll m)
{
    const ll INF = 1e18;
    ll ans = INF;
    for (ll i = 1; i * i <= m + 10 * i && i <= n; i++)
    {
        ll j = m / i;
        for (ll k = max(1LL, j - 10); k <= min(n, j + 10); k++)
        {
            ll tmp = i * k;
            if (tmp < m) continue;
            ans = min(ans, tmp);
        }
    }
    if (ans == INF) ans = -1;
    return ans;
}



int main()
{

    ll n, m;
    cin >> n >> m;
    cout << solve2(n, m) << endl;
    //cout << ans << endl;
    return 0;
}