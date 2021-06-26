//ABC_206_C
//Swappable
//171
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    rep(i, n)
    {
        cin >> a[i];
        ++mp[a[i]];
    }
    ll ans = 0;
    map<int, int> mp2;

    rep(i, n)
    {
        ++mp2[a[i]];
        ans += n - i - 1 - (mp[a[i]] - mp2[a[i]]);
        //ans += max(0,n-i - mp[a[i]]);
    }
    cout << ans << endl;

    return 0;
}