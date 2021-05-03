//ABC_165_A_We_Love_Golf
//25
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n:++i)
using namespace std;
 int main()
 {
     int k,a,b;
     cin >> k >> a >> b;
     string ans;
     if(a/k != b/k || a%k==0) ans = "OK";
     else ans = "NG";
     cout << ans << endl;
     return 0;
 }