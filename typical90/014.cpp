//014
//*3
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,int>;


int main()
{
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll ans = 0;
    rep(i,n)ans += abs(a[i]-b[i]);
    cout << ans << endl;
    return 0;
}
