//026
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
        int a,b;
        cin >> a >> b;
        --a,--b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);   
    }
    vector<int> prm;
    queue<int> q;
    q.emplace(0);
    prm.emplace_back(0);
    vector<int> used(n,-1);
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        for(auto a:g[s])
        {
            if(used[a] != -1) continue;
            used[a] = 1;
            prm.emplace_back(a);
            q.emplace(a);
        }
    }
    reverse(prm.begin(),prm.end());
    vector<int> ans(n,-1);
    int cnt = 0;
    for(auto a:prm)
    {
        bool ok = true;
        for(auto b:g[a])
        {
            if(ans[b] == 1) ok = false;
        }
        if(ok) 
        {
            ans[a] = 1;
            ++cnt;
            if(cnt*2 == n) break;
        }
    }
    for(int i =0;i<n;++i)
    {
        if(ans[i] == 1) cout << i+1 << endl;
    }
    return 0;
}