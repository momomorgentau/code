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
    vector<int> t(n);
    vector<int> l(n);
    vector<int> r(n);
    rep(i, n)
    {
        cin >> t[i] >> l[i] >> r[i];
        l[i] *= 2;
        r[i] *= 2;
        if (t[i] == 2) r[i] -= 1;
        else if (t[i] == 3) l[i] += 1;
        else if (t[i] == 4)
        {
            l[i] += 1;
            r[i] -= 1;
        }
    }
    ll ans = 0;
    rep(i, n)reps(j, i + 1, n)
    {
        if (max(l[i], l[j]) <= min(r[i], r[j])) ++ans;
    }
    cout << ans << endl;

    return 0;
}