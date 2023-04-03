//----------------------------
// ABC 296 C
// Gap Existence
// 162
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    ll n, x;
    cin >> n >> x;
    map<ll, int> mp;
    vector<ll> a(n);

    rep(i, n) cin >> a[i];
    rep(i, n)
    {
        mp[a[i]]++;
    }
    for (const auto& e : a)
    {
        ll t = x + e;
        if (mp.count(t))
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}