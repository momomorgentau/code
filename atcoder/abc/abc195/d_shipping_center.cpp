//ABC195_D_Shipping_Center
//945
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n,m,q;
    cin >> n >> m >> q;
    vector<P> vw(n);
    vector<int> x(m);
    rep(i,n)
    {
        int w,v;
        cin >> w >> v;
        vw[i] = make_pair(v,w);
    }
    sort(vw.rbegin(),vw.rend());
    rep(i,m) cin >> x[i];

    rep(i,q)
    {
        int ans = 0;
        int q1,q2;
        cin >> q1 >> q2;
        --q1;--q2;
        vector<int> qw;
        rep(i,m)
        {
            if(q1 <= i && i <= q2) continue;
            qw.emplace_back(x[i]);
        }
        sort(qw.begin(),qw.end());
        for(auto[vi,wi]:vw)
        {
            rep(qwi,qw.size())
            {
                if(wi > qw[qwi]) continue;
                qw[qwi] = -1;
                ans += vi;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}


