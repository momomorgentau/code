#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int mod = 998244353;
int dp[200010];
int main() {

    int n, k;
    cin >> n >> k;
    vector<P> act;
    vector<int> sum(n + 1, 0);
    rep(i, k) {
        int l, r;
        cin >> l >> r;
        act.emplace_back(l, r);
    }

    dp[0] = 0;
    dp[1] = 1;
    sum[0] = 0;
    sum[1] = 1;
    for (int i = 2; i < n + 1; ++i) {
        for (auto a : act) {
            int l = a.first;
            int r = a.second;

            l = max(0, i - l);
            r = max(0, i - r - 1);
            int p = (sum[l] - sum[r]) % mod;
            if (p < 0) p += mod;
            dp[i] = (dp[i] + p) % mod;
        }
        sum[i] = (sum[i - 1] + dp[i]) % mod;
    }
    cout << dp[n] << endl;
    return 0;
}