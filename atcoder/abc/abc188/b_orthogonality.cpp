//ABC_188_B_Orthogonality
//15
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    ll sum = 0;
    rep(i, n) sum += a[i] * b[i];

    if (sum == 0) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}