//597
//abc137_c_green_bin
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<map<char, int>> s;
    multiset<map<char, int>> ms;
    rep(i, n)
    {
        string si;
        cin >> si;
        map<char, int> mp;
        for (char e : si) ++mp[e];
        s.insert(mp);
        ms.insert(mp);
    }
    ll ans = 0;
    for (auto itr = s.begin(); itr != s.end(); ++itr)
    {
        ll c = ms.count(*itr);
        ans += c * (c - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}
