//------------------------------
//ABC_216_E
//Amusement Park
//1084
//------------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    ll n, k;
    cin >> n >> k;
    set<ll, greater<ll>> s;
    map<ll, ll> mp;
    rep(i, n)
    {
        int a;
        cin >> a;
        s.insert(a);
        ++mp[a];
    }
    ll ans = 0;
    while (s.size() > 1)
    {
        auto it = s.begin();
        ll n1 = *it;
        ll n2 = *(++it);

        ll nd = n1 - n2;
        ll tn = (n1 - n2) * mp[n1];
        if (k < tn)
        {
            tn = k / mp[n1];
            k %= mp[n1];
            ans += (((n1 + 1) * n1) / 2 - ((n1 - tn) * (n1 + 1 - tn)) / 2) * mp[n1];
            ans += (n1 - tn) * k;
            cout << ans << endl;
            return 0;
        }

        k -= tn;

        ans += (((n1 + 1) * n1) / 2 - ((n1 - nd) * (n1 + 1 - nd)) / 2) * mp[n1];

        s.erase(n1);
        mp[n2] += mp[n1];
    }


    ll n1 = *(s.begin());
    ll tn = n1 * mp[n1];
    if (k < tn)
    {
        tn = k / mp[n1];
        k %= mp[n1];
        ans += (((n1 + 1) * n1) / 2 - ((n1 - tn) * (n1 + 1 - tn)) / 2) * mp[n1];
        ans += (n1 - tn) * k;
        cout << ans << endl;
        return 0;
    }

    ans += (((n1 + 1) * n1) / 2) * mp[n1];



    cout << ans << endl;
    return 0;
}