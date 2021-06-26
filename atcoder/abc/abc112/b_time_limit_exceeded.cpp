//ABC_112_B
//Time_Limit_Exceeded
//95
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n,t; cin >> n >> t;
    int ans = 1e9;
    rep(i,n)
    {
        int a,b; cin >> a >> b;
        if(b<=t) ans = min(ans,a);
    }
    if(ans == 1e9) cout << "TLE" << endl;
    else cout << ans << endl;

    return 0;
}