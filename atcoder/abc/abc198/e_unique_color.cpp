//ABC_198_E
//Unique_Color
//1161
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int N = 1e5;
int c[N],color[N],used[N];
vector<vector<int>> g;
vector<int> ans;

 
void dfs(int a)
{
    int ca = c[a];
    //掲示板に書かれてなければ良い頂点
    //記録する
    if(color[ca] == 0) ans.emplace_back(a+1);
    used[a] = 1;
    //+1して次の頂点
    ++color[ca];
    for(auto t:g[a])
    {
        if(used[t] == 1) continue;
        dfs(t);
    }
    //戻るときには-1する
    --color[ca];
}

int main()
{
    int n;
    cin >> n;
    g.resize(n);
    rep(i,n) cin >> c[i];
    rep(i,n) --c[i];
    rep(i,n-1)
    {
        int a,b;
        cin >> a >> b;
        --a,--b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    
    dfs(0);
    sort(ans.begin(),ans.end());
    for(auto a:ans) cout << a << endl;

    return 0;
}