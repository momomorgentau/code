//046
//I_Love_46
//*3

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int M = 46;
int main()
{
    int n;
    cin >> n;
    vector<int> A(M), B(M), C(M);
    rep(i, n) { int s; cin >> s; ++A[s % M]; }
    rep(i, n) { int s; cin >> s; ++B[s % M]; }
    rep(i, n) { int s; cin >> s; ++C[s % M]; }
   
    ll ans = 0;
    rep(i, M)rep(j, M)rep(k,M)
    {
        if ((i + j + k) % M != 0) continue;
        ans += (ll)A[i] * B[j] * C[k];
    }
    cout << ans << endl;
    return 0;
}