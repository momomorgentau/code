//051
//Typical_Shop
//*5

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int M = 40;
int main()
{
    ll n, k, p;
    cin >> n >> k >> p;
    vector<vector<ll>> S1(M+5), S2(M+5);
    S1[0].emplace_back(0);
    S2[0].emplace_back(0);

    rep(i,n)
    {
        vector<vector<ll>> tmp = S1;
        ll a; cin >> a;
        rep(i, n)
        {
            for(auto ai:S1[i])
            {
                tmp[i + 1].emplace_back(ai + a);
            }
        }
        S1 = tmp;
        swap(S1,S2);
    }

    rep(i, M)
    {
        sort(S2[i].begin(), S2[i].end());
    }
    ll ans = 0;
    rep(i, k+1)
    {
        for (auto si : S1[i])
        {
            ans += upper_bound(S2[k-i].begin(), S2[k-i].end(), p - si) - S2[k-i].begin();
        }
    }
    cout << ans << endl;
    return 0;
}