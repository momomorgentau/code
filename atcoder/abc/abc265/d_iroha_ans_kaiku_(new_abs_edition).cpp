//----------------------------
//ABC 265 D
//Iroha and Haiku (New ABC Edition)
//727
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    ll n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    set<ll> st;
    ll s = 0;
    st.insert(0);
    rep(i, n)
    {
        s += a[i];
        st.insert(s);
    }
    bool ok = false;
    for (const auto& si : st)
    {
        // p‚ÌğŒ
        if (st.find(si + p) == st.end())continue;
        // q‚ÌğŒ
        if (st.find(si + p + q) == st.end()) continue;
        //r‚ÌğŒ
        if (st.find(si + p + q + r) == st.end()) continue;
        ok = true;
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}