//ABC_205_D
//Kth_Excluded
//713
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int,int,int>;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    while (q--)
    {
        ll k;
        cin >> k;
        ll ac = 0;
        ll wa = 1e18+1e9;
        while (wa - ac > 1)
        {
            ll wj = (wa + ac) / 2;
            ll idx = upper_bound(a.begin(),a.end(),wj)-a.begin();
            if (wj - idx < k) ac = wj;
            else wa = wj;
        }
        cout << ac+1 << endl;
    }
    return 0;
}

