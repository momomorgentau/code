//ABC_186_B_Block_on_Grid
//27
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h)rep(j, w) cin >> a[i][j];
    int mn = 10000;
    rep(i,h)rep(j,w)
    {
        mn = min(mn, a[i][j]);
    }
    int ans = 0;
    rep(i, h)rep(j, w)
    {
        ans += a[i][j] - mn;
    }
    cout << ans << endl;
    return 0;
}