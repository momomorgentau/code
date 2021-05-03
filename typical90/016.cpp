//016
//*3
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;


int main()
{
    ll n,a,b,c;
    cin >> n >> a >> b >> c;
    int ans = 100100100;
    rep(i,10000)rep(j,10000-i)
    {
        ll rem = n - (ll)i*a - (ll)j*b;
        if(rem < 0) continue;
        if(rem%c != 0) continue;
        int k = rem /c;
        ans = min(ans,i+j+k);
    }
    cout << ans << endl;
    return 0;
}
