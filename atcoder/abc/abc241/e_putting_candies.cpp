//----------------------------
//ABC 241 E
//Putting Candies
//1248
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    ll n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    if (k <= n)
    {
        ll ans = 0;
        rep(i, k)
        {
            ans += a[ans % n];
        }
        cout << ans << endl;

        return 0;
    }
    queue<int> q;
    vector<int> used(n, -1);
    ll rem = 0;
    int p = -1;
    rep(i, n + 5)
    {
        if (used[rem] == 1)
        {
            p = rem;
            break;
        }
        used[rem] = 1;
        q.emplace(rem);
        rem = (rem + a[rem]) % n;
    }

    ll l = -1;
    ll r = 0;
    vector<int> pre, dur;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        if (t == p)
        {
            l = 0;
        }
        if (l >= 0)
        {
            dur.emplace_back(t);
            ++l;
        }
        else
        {
            pre.emplace_back(t);
            ++r;
        }
    }
    ll loop = (k - r) / l;
    ll f = (k - r) % l;
    vector<ll> count(n, 0);

    for (const auto& prei : pre)
    {
        count[prei]++;
    }
    ll fi = 0;
    for (const auto& duri : dur)
    {
        count[duri] = loop;
        if (fi < f)
        {
            count[duri]++;
            ++fi;
        }

    }

    ll ans = 0;
    rep(i, n)
    {
        ans += count[i] * a[i];
    }
    cout << ans << endl;

    return 0;
}