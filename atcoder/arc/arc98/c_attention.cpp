//653
//arc98_c_attention

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

const int inf = 1e9;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> e(n);
    vector<int> w(n);
    int ne = 0;
    int nw = 0;

    rep(i, n)
    {
        if (s[i] == 'E') ++ne;
        else ++nw;
        e[i] = ne;
        w[i] = nw;
    }

    int ans = inf;
    rep(i, n)
    {
        int now = 0;
        if (i - 1 > 0) now += w[i - 1];
        if (i + 1 < n) now += e[n - 1] - e[i];
        ans = min(ans, now);
    }
    cout << ans << endl;
    return 0;
}