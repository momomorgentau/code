//63
//abc148_c_snack
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main()
{
    ll a,b;
    cin >> a >> b;
    ll ans = lcm(a,b);
    cout << ans << endl;
    return 0;
}