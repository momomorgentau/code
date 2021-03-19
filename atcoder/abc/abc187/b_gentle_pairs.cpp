//ABC_187_B_Gentle_Pairs
//68
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;


int main() 
{
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    int ans = 0;
    rep(i, n)rep(j, n)
    {
        if (i <= j) continue;
        if (abs(y[i] - y[j]) <= abs(x[i] - x[j])) ++ans;
    }
    cout << ans << endl;
    return 0;
}