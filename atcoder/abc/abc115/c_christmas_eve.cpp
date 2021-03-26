//ABC_115_C_Christmas_Eve
//291
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    sort(h.rbegin(),h.rend());
    int ans = 1e9;
    rep(i,n-k+1)
    {
        ans = min(ans,h[i]-h[i+k-1]);
    }
    cout << ans << endl;
    return 0;
}