//330
//abc135_c_city_savers
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n);
    for (auto& e : a) cin >> e;
    for (auto& e : b) cin >> e;
    b.emplace_back(0);
    ll ans = 0;

    rep(i, n + 1)
    {
        ans += min(a[i], b[i]);
        if (i == n) continue;
        int r = max(0, b[i] - a[i]);
        ans += min(a[i + 1], r);
        a[i + 1] = max(0, a[i + 1] - r);

    }
    cout << ans << endl;
    return 0;
}


