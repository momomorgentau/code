//13
//abc130_a_rounding
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int x,a;
    cin >> x >> a;
    int ans;
    if(x<a) ans = 0;
    else ans = 10;
    cout << ans << endl;
    return 0;
}