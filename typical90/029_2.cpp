//029
//*5
//task2
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int w, n; cin >> w >> n;
    vector<int> L(n), R(n);
    rep(i, n) cin >> L[i] >> R[i];
    vector<int> c;
    rep(i, n)
    {
        c.emplace_back(L[i]);
        c.emplace_back(R[i]);
    }
    sort(c.begin(), c.end());
    vector<int> g(c.size());
    rep(i, n)
    {
        int l = lower_bound(c.begin(), c.end(), L[i]) - c.begin();
        int r = lower_bound(c.begin(), c.end(), R[i]) - c.begin();
        int now = 0;
        reps(i, l, r + 1) now = max(now, g[i]);
        reps(i, l, r + 1) g[i] = now + 1;
        cout << now + 1 << endl;
    }

    return 0;
}