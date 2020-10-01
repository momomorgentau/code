#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
const int mod = pow(10, 9) + 7;
int main() {
    int s;
    cin >> s;

    vector<int> dp(s + 1);
    dp[0] = 1;
    rep(i, s + 1) {
        rep(j, i - 2) {
            dp[i] = (dp[i] + dp[j]) % mod;
        }
    }
    cout << dp[s] << endl;
    return 0;
}