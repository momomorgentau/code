//ABC_123_D_Cake_123
//1489
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int x,y,z,k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x),b(y),c(z);
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];

    vector<ll> ab;
    for(auto ai:a)for(auto bi:b) 
    {
        ab.emplace_back(ai+bi);
    }
    sort(ab.rbegin(),ab.rend());
    sort(c.rbegin(),c.rend());
    
    vector<ll> ans;
    rep(i,min(x*y,k))rep(j,z) 
    {
        ans.emplace_back(ab[i]+c[j]);
    }
    sort(ans.rbegin(),ans.rend());
    rep(i,k) cout << ans[i] << endl;
    return 0;
}
