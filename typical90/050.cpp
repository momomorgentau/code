//050
//Stair_Jump
//*3
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int M = 2e5;
const int mod = 1e9+7;
ll dp[M + 10];
int main()
{
    int n, l;
    cin >> n >> l;
    dp[0] = 1;
    rep(i, n)
    {
        dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
        dp[i + l] = (dp[i + l] + dp[i]) % mod;
    }
    cout << dp[n] << endl;
    return 0;
}