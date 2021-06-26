//ABC_202_C
//Made_Up
//204
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int N = 1e5;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];

    vector<int> A(N + 5), B(N + 5);
    rep(i, n) ++A[a[i]];
    rep(i, n) ++B[b[c[i]-1]];
    ll ans = 0;
    rep(i, N+3) ans += (ll)A[i] * B[i];
    cout << ans << endl;
    return 0;
}