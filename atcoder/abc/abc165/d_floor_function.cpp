//ABC_165_D_Floor_Function
//600
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n:++i)
using namespace std;
using ll = long long;
 int main()
 {
     int a;
     ll b, n;
     cin >> a >> b >> n;
     ll x = b-1;
     if(x > n) x = n;

     ll ans = (ll)(a*x)/b;
     ans -= a * (x/b);
     cout << ans << endl;

 }