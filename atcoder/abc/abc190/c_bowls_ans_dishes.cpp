//abc190_c_bowls_and_dishes
//472
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

//////////////
//solve1
int n, m, k;
int a[105];
int b[105];
int c[20];
int d[20];

int dfs(int ki,set<int> si)
{
    if (ki == k)
    {
        int ta = 0;
        rep(i, m) if (si.count(a[i]) && si.count(b[i])) ++ta;
        return ta;
    }

    set<int> si1 = si, si2 = si;
    si1.emplace(c[ki]);
    si2.emplace(d[ki]);

    return max(dfs(ki + 1, si1), dfs(ki + 1, si2));
}

int main()
{
    cin >> n >> m;
    rep(i, m) cin >> a[i] >> b[i];
    cin >> k;
    rep(i, k) cin >> c[i] >> d[i];

    set<int> s;
    cout << dfs(0, s) << endl;

    return 0;
}

////////////////
//solve2
int main()
{
    int n, m;
    cin >> n >> m;
    vector<P> ab(m);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ab[i] = make_pair(a, b);
    }
    int k;
    cin >> k;
    vector<P> cd(k);
    rep(i, k)
    {
        int c, d;
        cin >> c >> d;
        --c, --d;
        cd[i] = make_pair(c, d);
    }
    int ans = 0;

    rep(i, 1 << k)
    {
        int tk = i;
        vector<bool> p(n);
        rep(j, k)
        {
            int ci, di;
            tie(ci, di) = cd[j];
            if ((tk >> j) & 1) p[ci] = true;
            else p[di] = true;
        }
        int tans = 0;
        rep(j, m)
        {
            int ai = ab[j].first;
            int bi = ab[j].second;

            if (p[ai] && p[bi]) ++tans;
        }
        ans = max(ans, tans);
    }
    cout << ans << endl;
    return 0;
}

