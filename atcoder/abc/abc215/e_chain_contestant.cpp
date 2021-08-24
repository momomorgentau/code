//ABC_215
//Chain Contestant
//1413
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

const int mod = 998244353;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    vector<vector<ll>> dp(1 << 10, vector<ll>(11, 0));
    dp[0][10] = 1;
    for (auto const& c : s)
    {
        vector<vector<ll>> now = dp;
        int digit = c - 'A';
        int add = 1 << digit;
        rep(bit, 1 << 10)
        {
            rep(pre, 11)
            {
                if (((bit & add) != 0) && pre != 10 && pre != digit) continue;
                now[bit | add][digit] += dp[bit][pre];
                now[bit | add][digit] %= mod;
            }
        }
        swap(dp, now);
    }

    ll ans = 0;
    reps(i, 1, 1 << 10)
    {
        rep(j, 10)
        {
            ans = (ans + dp[i][j]) % mod;
        }
    }
    cout << ans << endl;


    return 0;
}