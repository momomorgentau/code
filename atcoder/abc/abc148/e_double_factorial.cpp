//818
//abc148_e_double_factrial
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    if(n&1) ans = 0;
    else
    {
        ll d = 5*2;
        while(d <= n)
        {
            ans += n / d;
            d *= 5;
        }
    }
    cout << ans << endl;
    return 0;
}