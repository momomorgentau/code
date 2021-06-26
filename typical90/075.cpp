//075
//Magic_For_Balls
//*3
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    ll n;
    cin >> n;
    ll m = 0;
    for (ll i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            ++m;
            n /= i;
        }
    }
    if (n != 1) ++m;
    

    int ans = 0;
    ll t = 1;

    rep(i, 63)
    {
        if (m <= t) break;
        t *= 2;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}