//518
//abc131_anti_division
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll cd = lcm(c,d);
    ll ans = b-a+1;
    ans -= b/c - (a-1)/c;
    ans -= b/d - (a-1)/d;
    ans += b/(cd) - (a-1)/(cd);
    cout << ans << endl;
    return 0;
}