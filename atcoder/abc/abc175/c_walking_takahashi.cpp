#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll = long long;
int main()
{
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    ll ans = 0;
    //0‚É“’B‚µ‚È‚¢ê‡
    if (x / d > k) ans = x - d * k;
    else
    {
        ll ans_r = x % d;
        ll ans_l = abs(ans_r - d);
        if ((k - x / d) % 2 == 0) ans = ans_r;
        else ans = ans_l;

    }
    cout << ans << endl;
    return 0;
}