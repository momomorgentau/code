//ABC_127_C_Prison
//239
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
    vector<int> g(n);
    rep(i, m)
    {
        int l, r;
        cin >> l >> r;
        --l;
        ++g[l];
        if(r < n) --g[r];
    }

    rep(i, n-1) g[i + 1] += g[i];
    int ans = 0;
    rep(i, n)
    {
        if (g[i] == m) ++ans;
    }
    cout << ans << endl;
    return 0;
}