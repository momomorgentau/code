#include<bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll = long long;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n), c(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> c[i];
    rep(i, n) --p[i];

    ll ans = INT_MIN;

    rep(i, n) {
        vector<int> loop; //loop‚·‚é‡—ñ
        int x = i;
        ll loop_sum = 0;

        while (1) {
            loop.emplace_back(c[x]);
            loop_sum += c[x];
            x = p[x];
            if (x == i) break;
        }

        int l = loop.size();
        ll rem_sum = 0;
        ll ans_sum = 0;
        rep(st, l) {
            rem_sum += loop[st];
            if (st + 1 > k) break;
            ll e = (k - (st + 1)) / l;
            ans_sum = rem_sum + max((ll)0, loop_sum) * e;
            ans = max(ans, ans_sum);
        }

    }
    cout << ans << endl;
    return 0;
}