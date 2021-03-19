//ABC_188_D_Snuke_Prinme
//933
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;


int main()
{
    int n, c;
    cin >> n >> c;
    set<int> time;
    map<int, vector<ll>> m;

    ll mxb = 0;
    rep(i, n)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        m[a-1].emplace_back(c);
        m[b].emplace_back(-c);
        time.emplace(a-1);
        time.emplace(b);
        mxb = max(mxb, b);
    }

    //sort(time.begin(), time.end());
    ll sum = 0;
    ll ts = 0;
    ll pa = 0;

    for(auto t:time)
    {

        ll tt = 0;
        ll tmt = 0;
        ll tpt = 0;

        for (auto tm : m[t])
        {
            if (tm < 0) tmt += tm;
            else tpt += abs(tm);
        }
        if (ts < c) sum += (ts) * (t - pa);
        else sum += c * (t - pa);
        pa = t;
        ts += tmt;
        ts += tpt;

    }
    cout << sum << endl;
    return 0;
}