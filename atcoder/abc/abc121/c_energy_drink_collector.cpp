//ABC_121_C_Enegy_Drink_Collector
//360
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<pair<ll,ll>> ab(n);
    rep(i,n)
    {
        ll a,b;
        cin >> a >> b;
        ab[i] = make_pair(a,b);
    }
    sort(ab.begin(),ab.end());
    ll ans = 0;
    ll cnt = 0;
    for(auto [ai,bi]:ab)
    {
        if(cnt >= m) break;
        if(cnt + bi <= m)
        {
            ans += ai*bi;
            cnt += bi;
        }
        else
        {
            ans += ai * (m-cnt);
            cnt = m;
        }
    }
    cout << ans << endl;

    return 0;
}