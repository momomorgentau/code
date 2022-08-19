//Educational DP Contest J
//Sushi
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<bool> dp(k + 10, false);
    rep(i, k + 1)
    {
        for (const auto& ai : a)
        {
            if (i - ai < 0) continue;
            dp[i] = dp[i] | !dp[i - ai];
        }
    }
    if (dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}