//022
//*2
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main()
{
    ll a,b,c;
    cin >> a >> b >> c;
    ll g = __gcd(a,b);
    g = __gcd(g,c);
    ll ans = (a+b+c)/g-3;
    cout << ans << endl;

    return 0;
}