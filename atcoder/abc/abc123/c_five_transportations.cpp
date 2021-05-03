//ABC_123_C_Five_Transportations
//643
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    ll n;
    vector<ll> v(5);
    cin >> n;
    rep(i,5) cin >> v[i];
    ll mn = *min_element(v.begin(),v.end());
    ll ans = (n+mn-1)/mn + 4;
    cout << ans << endl;
    
    return 0;
}
