//27
//abc181_b_trapezoid_sum
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main() 
{
    int n;
    cin >> n;
    ll ans = 0;
    rep(i, n) 
    {
        ll a, b; cin >> a >> b;
        ll s1 = b * (b + 1) / 2;
        ll s2 = a * (a + 1) / 2;
        ans += s1 - s2 + a;
    }

    cout << ans << endl;
    return 0;
}
