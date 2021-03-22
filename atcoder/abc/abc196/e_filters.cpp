//ABC_196_E_Filters
//1650
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n,q;
    cin >> n;
    const ll INF = ll(1)<<60;
    ll l = -INF, r = INF;
    ll s = 0;
    rep(i,n)
    {
        ll a,t;
        cin >> a >> t;
        if(t == 1)
        {
            l += a;
            r += a;
            s += a;
        }
        else if(t ==2)
        {
            l = max(l,a);
            r = max(r,a);
        }
        else
        {
            l = min(l,a);
            r = min(r,a);
        }
    }
    cin >> q;
    rep(i,q)
    {
        ll x;
        cin >> x;
        x += s;
        ll ans = x;
        if(x <= l) ans = l;
        else if(r <= x) ans = r;
        printf("%ld\n",ans);
    }

    return 0;
}
