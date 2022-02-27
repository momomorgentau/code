//----------------------------
//ABC 241 D
//Sequence Query
//1177
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int q; cin >> q;
    multiset<ll> ms;
    const ll INF = 2e18;
    rep(i, 10) ms.insert(INF);
    rep(i, 10) ms.insert(-1);

    while (q--)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            ll x; cin >> x;
            ms.insert(x);
        }
        else if (c == 2)
        {
            ll x;
            int k;
            cin >> x >> k;
            auto it = ms.upper_bound(x);
            if (*it > x)
            {
                --it;
            }
            ll t = -2;
            --k;
            rep(i, k)
            {
                --it;
            }
            cout << *it << endl;
        }
        else if (c == 3)
        {
            ll x;
            int k;
            cin >> x >> k;
            auto it = ms.lower_bound(x);

            --k;
            rep(i, k)
            {
                ++it;
            }
            ll t = *it;
            if (t == INF) t = -1;
            cout << t << endl;

        }
    }
    return 0;
}
