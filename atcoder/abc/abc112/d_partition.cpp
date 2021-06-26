//ABC_112_D
//Partition
//1025
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n,m;
    cin >> n >> m;
    ll ans = 1;
    ll M = m;
    ll R = 1;
    for(ll i = 1;i*i <= M;++i)
    {
        R = i;
        if(m % i != 0)continue;
        ll g = m / i;
        if(m/g < n) continue;
        ans *= g;
        m /= g;
    }
    for(ll i = R;i >= 1;--i)
    {
        if(m % i != 0)continue;
        if(m/i < n) continue;
        ans *= i;
        m /= i;
    }
    cout << ans << endl;
    return 0;
}