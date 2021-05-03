//833
//abc125_d_flipping_signs
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int n;
    cin >> n;
    bool minus_odd = false;
    bool zero = false;
    int min_abs = 1e9;
    ll ans = 0;

    rep(i,n)
    {
        int a; cin >> a;
        if(a < 0) minus_odd = !minus_odd;
        else if(a == 0) zero = true;
        int a_abs = abs(a);
        min_abs = min(min_abs,a_abs);
        ans += a_abs;
    }
    if(!zero && minus_odd) ans -= 2*min_abs;
    cout << ans << endl;
    return 0;
}