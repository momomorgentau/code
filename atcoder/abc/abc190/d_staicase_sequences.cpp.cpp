//ABC_190_D_Staircase_Sequences
//722
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll n;
    cin >> n;
    ll odd = 1;
    for (ll i = 2; i*i <= n*10000; ++i)
    {
        ll p = i;
        ll r = n % p;
        ll q = n / p;
        if (p & 1)
        {
            if (r == 0 && q - p / 2 > 0) ++odd;
        }
        else
        {
            if (r == p / 2 && q - (p - 1) / 2 > 0) ++odd;
        }
    }
    ll ans = odd * 2;
    cout << ans << endl;

    return 0;
}