//ABC_127_D_Integer_Cards
//887
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    map<int, int, greater<int>> mp;
    rep(i, n)
    {
        ll a;
        cin >> a;
        ++mp[a];
    }
    rep(i, m)
    {
        int b, c;
        cin >> b >> c;
        mp[c] += b;
    }
    ll ans = 0;
    int cnt = 0;
    for (auto mpi : mp)
    {
        int ci = mpi.first;
        int bi = mpi.second;
        if (cnt + bi < n) ans += (ll)bi * ci;
        else
        {
            ans += ((ll)n - cnt) * ci;
            break;
        }
        cnt += bi;
    }
    cout << ans << endl;
    return 0;
}