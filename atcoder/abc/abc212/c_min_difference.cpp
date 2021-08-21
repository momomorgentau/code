//ABC_212_C
//Min_Difference
//246
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> A(n), B(m);
    rep(i, n) cin >> A[i];
    rep(i, m) cin >> B[i];
    ll INF = 1e18;
    B.emplace_back(INF);
    B.emplace_back(-INF);
    sort(B.begin(), B.end());
    ll ans = INF;
    for (auto const& a : A)
    {
        int idx = lower_bound(B.begin(), B.end(), a) - B.begin();
        ans = min({ abs(a - B[idx - 1]), abs(a - B[idx]), ans });
    }
    cout << ans << endl;

    return 0;
}