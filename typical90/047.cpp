//047
//Monochromatic Diagonal
//*7
//task1
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int c2i(char c)
{
    if (c == 'R') return 0;
    else if (c == 'G') return 1;
    else if (c == 'B') return 2;
    else return 1e9;
}
int main()
{
    int n;
    string  s, t;
    cin >> n >> s >> t;
    vector<vector<int>> g(n, vector<int>(n, -1));
    rep(i, n)
    {
        int si = c2i(s[i]);
        rep(j, n)
        {
            int tj = c2i(t[j]);
            if (si == tj) g[i][j] = si;
            else g[i][j] = 3 - si - tj;
        }
    }
    int ans = 0;
    rep(j, n)
    {
        int x = g[0][j];
        bool ok = true;
        rep(i, n)
        {
            if (j + i >= n)break;
            if (g[i][j + i] != x)
            {
                ok = false;
                break;
            }
        }
        if (ok) ++ans;
    }
    reps(i, 1, n)
    {
        int x = g[i][0];
        bool ok = true;
        rep(j, n)
        {
            if (j + i >= n)break;
            if (g[i + j][j] != x)
            {
                ok = false;
                break;
            }
        }
        if (ok) ++ans;
    }
    cout << ans << endl;
    return 0;
}