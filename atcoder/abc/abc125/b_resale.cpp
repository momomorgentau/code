//ABC_125_B_Resale
//61
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<int> v(n);
    vector<int> c(n);
    rep(i, n) cin >> v[i];
    rep(i, n) cin >> c[i];

    rep(i, n)
    {
        ans += max(0, v[i] - c[i]);
    }
    cout << ans << endl;
    return 0;
}