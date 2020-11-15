//diff284
//abc183_c_travel_fast
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;
using P = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> t(n, vector<int>(n));
    rep(i, n)rep(j, n) cin >> t[i][j];

    vector<int> p;
    rep(i, n - 1) p.emplace_back(i + 1);
    int ans = 0;

    do
    {
        int st = t[0][p[0]];
        rep(i, n - 2) st += t[p[i]][p[i + 1]];
        st += t[p[n - 2]][0];
        if (st == k) ++ans;
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;

    return 0;
}