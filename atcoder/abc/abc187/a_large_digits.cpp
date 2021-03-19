//ABC_187_A_Large_Digits
//8
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;


int main() 
{
    string a, b;
    cin >> a >> b;
    int sa = 0, sb = 0;
    rep(i, 3) sa += a[i] - '0';
    rep(i, 3) sb += b[i] - '0';
    int ans = max(sa, sb);
    cout << ans << endl;
    
    return 0;
}