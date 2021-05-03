//ABC_196_C_Doubled
//244
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1;i <= (ll)1e6;++i)
    {
        ll cnt = 1;
        ll tmp = i;
        while(tmp>0)
        {
            tmp /=10;
            cnt*=10;
        }
        ll now = i * cnt + i;
        if(now <= n) ++ans;
    }
    cout << ans << endl; 
    return 0;
}
