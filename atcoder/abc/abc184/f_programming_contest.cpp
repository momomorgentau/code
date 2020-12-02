//1423
//abc184_f_programming_contest
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> s1, s2;
    s1 = s2 = { 0 };

    rep(i, n)
    {
        int m = s1.size();
        rep(j, m)
        {
            s1.emplace_back(s1[j] + a[i]);
        }
        swap(s1, s2);
    }

    sort(s1.begin(), s1.end());
    ll ans = 0;

    for (auto x : s2)
    {
        if (x > t) continue;
        int idx = upper_bound(s1.begin(), s1.end(), t - x) - s1.begin();
        ans = max(ans, x + s1[idx - 1]);
    }
    cout << ans << endl;

    return 0;
}
