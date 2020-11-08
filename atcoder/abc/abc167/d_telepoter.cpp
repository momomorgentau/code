//639
//abc167d_telepoter
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i], --a[i];
    vector<int> apped(n, -1);
    vector<int> route(n);
    int c = 0;
    int np = 0;
    apped[0] = 0;
    while (1)
    {
        ++c;
        np = a[np];
        if (apped[np] != -1) break;
        apped[np] = c;
        route[c] = np;
        if (c == k)
        {
            cout << np + 1 << endl;
            return 0;
        }
    }

    int s = apped[np];
    int l = c - apped[np];

    k -= s;
    k %= l;
    cout << route[k + s] + 1 << endl;

    return 0;
}
