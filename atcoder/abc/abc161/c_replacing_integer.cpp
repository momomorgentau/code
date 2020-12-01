//149
//abc161_c_replacing_integer
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)

using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    ll n, k;
    cin >> n >> k;
    ll ans = n % k;
    ans = min(ans, k - ans);
    cout << ans << endl;
    return 0;
}
