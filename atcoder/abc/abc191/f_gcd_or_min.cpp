//ABC_191_F_GCD_or_MIN
//2333
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    unordered_map<int,int> mp;
    int mn = 1e9 + 5;
    rep(i, n)
    {
        int a;
        cin >> a;
        mn = min(mn, a);
        vector<int> d;
        for (ll i = 1; i * i <= a; ++i)
        {
            if (a % i != 0) continue;
            d.emplace_back(i);
            d.emplace_back(a/i);
        }
        for (int di : d) mp[di] = gcd(mp[di], a);
    }

    int ans = 0;
    for (auto [x, y] : mp)
    {
        if (x == y && x <= mn) ++ans;
    }
    cout << ans << endl;
    return 0;
}