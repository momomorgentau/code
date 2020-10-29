//422
//abc171 d replacing
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

const int mx = 1e5 + 5;

int main()
{
    int n; cin >> n;
    vector<int> ha(mx);
    ll ans = 0;
    rep(i, n)
    {
        int ta; cin >> ta;
        ++ha[ta];
        ans += ta;
    }
    int q; cin >> q;
    rep(i, q)
    {
        int b, c; cin >> b >> c;
        int d = c - b;
        ans += (ll)ha[b] * d;
        ha[c] += ha[b];
        ha[b] = 0;
        cout << ans << endl;
    }
    return 0;
}
