//----------------------------
//ABC_096_B
//Maximum Sum
//88
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    int m = max({a,b,c});
    ll ans = m * pow(2,k) + a + b + c - m;
    cout << ans << endl;
}