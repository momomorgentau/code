//ARC_115_B_Plus_Matrix
//629
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<vector<ll>> c(n,vector<ll> (n));
    rep(i,n)rep(j,n) cin >> c[i][j];
    vector<ll> a(n);
    vector<ll> b(n);
    //A1=0を仮定。
    rep(i,n) b[i] = c[0][i];
    rep(i,n) a[i] = c[i][0] - b[0];
    bool ok = true;
    rep(i,n)rep(j,n)
    {
        if(a[i]+b[j] != c[i][j]) ok = false;
    }
    if(ok)
    {
        ll mna = 0,mnb = 0;
        rep(i,n) mna = min(mna,a[i]);
        rep(i,n) mnb = min(mnb,b[i]);
        if(mna < 0)
        {
            rep(i,n) a[i] += abs(mna);
            rep(i,n) b[i] -= abs(mna);
        }
        if(mnb < 0)
        {
            rep(i,n) a[i] -= abs(mnb);
            rep(i,n) b[i] += abs(mnb);
        }
        

        cout << "Yes" << endl;
        rep(i,n) cout << a[i] << " ";
        cout << endl;
        rep(i,n) cout << b[i] << " ";
        cout << endl;
    }
    else cout << "No" << endl;
    return 0;
}

