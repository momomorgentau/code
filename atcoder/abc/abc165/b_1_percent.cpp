//ABC_165_B_1%
//89
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n:++i)
using namespace std;
using ll = long long;
 int main()
 {
     ll x;
     cin >> x;
     ll b = 100;
     int ans = 0;
     while(b < x)
     {
         ++ans;
         b += b/100;

     }
     cout << ans << endl;     
 }