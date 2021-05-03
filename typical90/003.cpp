//003
//*4
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    rep(i,n-1)
    {
        int u,v;
        cin >> u >> v;
        --u,--v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    
    vector<int> d(n);
    auto bfs = [&](int a)
    {
        rep(i,n) d[i] = 1e9;
        d[a] = 0;
        queue<int> q;
        q.emplace(a);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto v:g[u])
            {
                if(d[v] <= d[u]+1) continue;
                d[v] = d[u]+1;
                q.emplace(v);
            }
        }
            
    };

    bfs(0);
    bfs(distance(d.begin(),max_element(d.begin(),d.end())));
    cout << *max_element(d.begin(),d.end()) +1<< endl;
    
    return 0;
} 