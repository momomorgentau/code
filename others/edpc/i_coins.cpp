//Educational DP Contest I
//Coins
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n;
    cin >> n;
    vector<double> p(n);
    rep(i, n)cin >> p[i];
    vector<double> dp(n + 1);
    dp[0] = 1;
    rep(i, n)
    {
        vector<double> tmp(n + 1);
        rep(j, i + 1)
        {
            tmp[j + 1] += dp[j] * p[i];
            tmp[j] += dp[j] * (1.0 - p[i]);
        }
        swap(tmp, dp);
    }
    double ans = 0;
    reps(i, (n + 1) / 2, n + 1)
    {
        ans += dp[i];
    }
    printf("%.10f\n", ans);
    return 0;
}