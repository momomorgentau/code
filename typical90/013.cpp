//013
//*6
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,int>;


int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<P>> g(n);
    rep(i,m)
    {
        int a,b,c;
        cin >> a >> b >> c;
        --a, --b;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }

    auto dij=[&](int a,vector<ll> &d)
    {
        priority_queue<Pl,vector<Pl>,greater<Pl>> pq;
        pq.emplace(0,a);

        while(!pq.empty())
        {
            int s;
            ll c;
            tie(c,s) = pq.top();
            pq.pop();
            if(d[s] < c) continue;
            for(auto [gt,gc]:g[s])
            {
                if(d[gt]<=d[s]+gc) continue;
                d[gt] = d[s] + gc;
                pq.emplace(d[gt],gt);
            }
        }
    };
    const ll INF = 1e18;
    vector<ll> d1(n,INF),d2(n,INF);
    d1[0] = 0;
    d2[n-1] = 0;
    dij(0,d1);
    dij(n-1,d2);

    
    rep(i,n) cout << d1[i]+d2[i] << endl;    
    return 0;
}
