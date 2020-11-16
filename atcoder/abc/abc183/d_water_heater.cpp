//diff617
//abc183_d_water_heater
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;
using P = pair<int, int>;

//シミュレーション
int solve1()
{

    int n, w;
    cin >> n >> w;
    vector<P> e;
    rep(i, n)
    {
        int s, t, p;
        cin >> s >> t >> p;
        e.emplace_back(s, p);
        e.emplace_back(t, -p);
    }

    //まず、時間でソート、時間が同じ場合は負の値が先に来る
    sort(e.begin(), e.end());
    ll need = 0;
    for (P ei : e)
    {
        int pi;
        tie(ignore, pi) = ei;
        need += pi;
        if (need > w)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
//いもす法
int solve2()
{
    const int t_max = 2 * 1e5;
    int n, w;
    cin >> n >> w;

    vector<ll> a(t_max + 1, 0);

    rep(i, n)
    {
        int s, t, p;
        cin >> s >> t >> p;
        a[s] += p;
        a[t] -= p;
    }

    rep(i, t_max) a[i + 1] += a[i];

    ll max_w = *max_element(a.begin(), a.end());

    if (max_w <= w) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

int main()
{
    //solve1();
    solve2();
    return 0;
}

