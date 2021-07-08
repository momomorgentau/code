//085
//Multiplication085
//*4
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using T = tuple<int, int, int>;

int main()
{
    ll k;
    cin >> k;
    ll ans = 0;
    for (ll i = 1; i * i * i <= k; ++i)
    {
        if (k % i != 0) continue;
        ll ki = k / i;
        for (ll j = i; j * j <= ki; ++j)
        {
            if (ki % j != 0) continue;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}