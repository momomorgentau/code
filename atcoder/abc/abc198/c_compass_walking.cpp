//ABC_198_C
//Compass_Walking
//413
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll r,x,y;
    cin >> r >> x >> y;
    r *= r;
    ll d = x*x + y*y;
    ll ans = 1;
    while(d > r * ans*ans) ++ans;
    if(ans == 1)
    {
        if(d!= r) ++ans;
    }
    cout << ans << endl;
    return 0;
}