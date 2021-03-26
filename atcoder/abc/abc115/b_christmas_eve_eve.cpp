//ABC_115_B_Christmas_Eve_Eve
//50
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
    int mx = 0;
    rep(i,n)
    {
        int p; cin >> p;
        mx = max(mx,p);
        ans += p;
    }
    ans -= mx/2;
    cout << ans << endl;
    return 0;
}