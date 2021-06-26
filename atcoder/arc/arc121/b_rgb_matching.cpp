//ARC_121_B
//RGB_Matching
//1159
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<ll> r, g, b;

    rep(i, n*2)
    {
        ll a;
        char c;
        cin >> a >> c;
        if (c == 'R') r.emplace_back(a);
        if (c == 'G') g.emplace_back(a);
        if (c == 'B') b.emplace_back(a);
    }
    int nr = r.size();
    int ng = g.size();
    int nb = b.size();

    if (nr % 2 == 0 && nb % 2 == 0 && ng % 2 == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());

    if (nr == 0 || ng == 0 || nb == 0)
    {
        if (ng == 0)
        {
            swap(r, g);
            swap(nr, ng);
        }
        if (nb == 0)
        {
            swap(r, b);
            swap(nr, nb);
        }
        ll ans = 1e18;
        int idx1 = 0;
        int idx2 = 0;


        while (1)
        {
            ans = min(ans, abs(g[idx1] - b[idx2]));
            if (idx1 == ng - 1 && idx2 == nb - 1)break;
            else if (idx1 == ng - 1) ++idx2;
            else if (idx2 == nb - 1) ++idx1;
            else if (g[idx1] < b[idx2]) ++idx1;
            else ++idx2;
        }
        cout << ans << endl;
        return 0;

    }
    //rは絶対に偶数
    if (ng % 2 == 0) swap(r, g),swap(nr,ng);
    if (nb % 2 == 0) swap(r, b),swap(nr,nb);

    ll ans = 1e18;




    int idx1 = 0;
    int idx2 = 0;
    //bとgでペアを作る場合
    while (1)
    {
        ans = min(ans,abs(g[idx1] - b[idx2]));
        if (idx1 == ng - 1 && idx2 == nb - 1)break;
        else if (idx1 == ng - 1) ++idx2;
        else if (idx2 == nb - 1) ++idx1;
        else if (g[idx1] < b[idx2]) ++idx1;
        else ++idx2;
    }
    //aとb,aとgでペアを作る場合
    idx1 = 0;
    idx2 = 0;
    ll now1 = 1e18;
    int NG = -1;
    while (1)
    {
        if (now1 > abs(g[idx1] - r[idx2]))
        {
            now1 = abs(g[idx1] - r[idx2]);
            NG = idx2;
        }
        if (idx1 == ng - 1 && idx2 == nr - 1)break;
        else if (idx1 == ng - 1) ++idx2;
        else if (idx2 == nr - 1) ++idx1;
        else if (g[idx1] < r[idx2]) ++idx1;
        else ++idx2;
    }

    idx1 = 0;
    idx2 = 0;
    ll now2 = 1e18;
    while (1)
    {
        if (now2 > abs(b[idx1] - r[idx2]) && idx2 != NG)
        {
            now2 = abs(b[idx1] - r[idx2]);
        }
        if (idx1 == nb - 1 && idx2 == nr - 1)break;
        else if (idx1 == nb - 1) ++idx2;
        else if (idx2 == nr - 1) ++idx1;
        else if (b[idx1] < r[idx2]) ++idx1;
        else ++idx2;
    }
    ans = min(ans, now1 + now2);
    //aとb,aとgでペアを作る場合b->g

    idx1 = 0;
    idx2 = 0;
    now1 = 1e18;
    NG = -1;
    while (1)
    {
        if (now1 > abs(b[idx1] - r[idx2]))
        {
            now1 = abs(b[idx1] - r[idx2]);
            NG = idx2;
        }
        if (idx1 == nb - 1 && idx2 == nr - 1)break;
        else if (idx1 == nb - 1) ++idx2;
        else if (idx2 == nr - 1) ++idx1;
        else if (b[idx1] < r[idx2]) ++idx1;
        else ++idx2;
    }

    idx1 = 0;
    idx2 = 0;
    now2 = 1e18;
    while (1)
    {
        if (now2 > abs(g[idx1] - r[idx2]) && idx2 != NG)
        {
            now2 = abs(g[idx1] - r[idx2]);
        }
        if (idx1 == ng - 1 && idx2 == nr - 1)break;
        else if (idx1 == ng - 1) ++idx2;
        else if (idx2 == nr - 1) ++idx1;
        else if (g[idx1] < r[idx2]) ++idx1;
        else ++idx2;
    }
    ans = min(ans, now1+ now2);
    cout << ans << endl;
    return 0;
}