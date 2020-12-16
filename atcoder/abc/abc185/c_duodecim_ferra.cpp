//374
//abc185_c_duodecim_ferra
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

ll comb(int n, int a)
{
    ll r = 1;
    rep(i, a)
    {
        r *= ((ll)n - i);
        r /= ((ll)i + 1);
    }
    return r;
}

int main()
{
    int l;
    cin >> l;
    ll ans = comb(l - 1, 11);
    cout << ans << endl;
    return 0;
}