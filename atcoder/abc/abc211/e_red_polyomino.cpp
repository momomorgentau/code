//ABC_211_E
//Red Plyomino
//1823
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, int>;
using T = tuple<int, int, int>;

int n, k;
vector<string> S;
vector<int> dy = { 1,-1,0,0 };
vector<int> dx = { 0,0,-1,1 };
ll ans = 0;
set<ll> used;

void dfs(ll s, int now)
{
    if (used.count(s) != 0) return;
    used.emplace(s);

    if (now == k)
    {
        ++ans;
        return;
    }

    rep(i, n)rep(j, n)
    {
        ll bit = 1LL << (i * n + j);
        if (S[i][j] == '#') continue;

        bool ok = false;
        rep(k, 4)
        {
            int ni = i + dy[k];
            int nj = j + dx[k];
            if (ni < 0 || n <= ni) continue;
            if (nj < 0 || n <= nj) continue;
            if (s & (1LL << (ni * n + nj)))
            {
                ok = true;
                break;
            }
        }
        if (!ok && (now != 0)) continue;
        dfs(s | bit, now + 1);
        dfs(s, now);
    }

    return;
}



int main()
{
    cin >> n >> k;
    S.resize(n);
    rep(i, n) cin >> S[i];
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}