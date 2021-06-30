//079
//Two by Two
//*3
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;


int main()
{
    int h, w;
    cin >> h >> w;

    vector<vector<ll>> A(h, vector<ll>(w));
    vector<vector<ll>> B(h, vector<ll>(w));
    rep(i, h)rep(j, w) cin >> A[i][j];
    rep(i, h)rep(j, w) cin >> B[i][j];

    ll ans = 0;
    rep(i, h - 1)rep(j, w - 1)
    {
        ll d = -A[i][j] + B[i][j];
        A[i + 1][j] += d;
        A[i][j + 1] += d;
        A[i + 1][j + 1] += d;
        ans += abs(d);

    }
    bool ok = true;
    rep(i, h) if (A[i][w - 1] != B[i][w - 1]) ok = false;
    rep(i, w) if (A[h - 1][i] != B[h - 1][i]) ok = false;
    if (ok)
    {
        cout << "Yes" << endl;
        cout << ans << endl;
    }
    else cout << "No" << endl;

    return 0;
}
