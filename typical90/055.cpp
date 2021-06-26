//055
//Select5
//*2

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() 
{
    int n, p, q;
    cin >> n >> p >> q;
    vector<ll> a(n);
    rep(i, n)cin >> a[i];
    int ans = 0;
    rep(i, n)reps(j, i + 1, n)reps(k, j + 1, n)reps(l, k + 1, n)reps(m, l + 1, n)
    {
        ll now = a[i];
        now = (a[j] * now) % p;
        now = (a[k] * now) % p;
        now = (a[l] * now) % p;
        now = (a[m] * now) % p;
        if (now == q) ++ans;
    }
    cout << ans << endl;
    return 0;
}

