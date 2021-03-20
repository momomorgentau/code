//ABC_121_D_Xor_World
//1164
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll xor_bit(ll n,ll div)
{
    ll res = (n/div)*(div>>ll(1));
    res += max(ll(0),n%div-div/2+1);
    return res;
}

int main()
{
    ll a,b;
    cin >> a >> b;
    ll ans = 0;
    ll bit = 0;
    while((ll(1)<<bit) <= b)
    {
        ll div = (ll(1) << (bit+1));
        if(xor_bit(b,div) - xor_bit(a-1,div) & 1) ans += (ll(1)<<bit);
        ++bit;
    }
    cout << ans << endl;
}
/*
0 000
1 001
2 010
3 011
4 100
5 101
6 110
7 111

*/
