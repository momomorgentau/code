//991
//abc161_d_lunlun_number
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)

using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int k;
    cin >> k;
    queue<ll> q;
    reps(i, 1, 10) q.emplace(i);
    rep(i, k - 1)
    {
        ll qi = q.front();
        q.pop();
        int qm = qi % 10;
        if (qm != 0) q.emplace(10 * qi + qm - 1);
        q.emplace(10 * qi + qm);
        if (qm != 9) q.emplace(10 * qi + qm + 1);
    }
    ll ans = q.front();
    cout << ans << endl;

    return 0;
}