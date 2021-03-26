//ABC_118_C_Streamline
//612
//ABC_117_C_Streamline
//612
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> x(m);
    rep(i,m) cin >> x[i];
    sort(x.begin(),x.end());
    vector<int> d(m-1);
    rep(i,m-1) d[i] = x[i+1]-x[i];
    sort(d.begin(),d.end());
    ll ans = 0;
    rep(i,m-n) ans += d[i];
    cout << ans << endl;
    return 0;
}