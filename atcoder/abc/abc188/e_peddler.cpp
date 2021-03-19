//abc188_e_peddler
//1170
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<int>> edge(n);
    rep(i,m)
    {
        int x,y;
        cin >> x >> y;
        --x;--y;
        edge[x].emplace_back(y);
    }
    const int inf = 1e9+7;
    vector<int> mn(n,inf);
    vector<bool> memo(n,false);

    rep(i,n)
    {
        if(memo[i]) continue;
        queue<int> q;
        q.emplace(i);
        while(!q.empty())
        {
            int now = q.front();
            q.pop();
            memo[now] = true;
            int tmn = min(mn[now],a[now]);
            for(auto qi:edge[now])
            {
                if(tmn > mn[qi]) continue;
                mn[qi] = tmn;
                q.emplace(qi);
            }
        }
    }
    
    int ans = -inf;
    rep(i,n) ans = max(ans,a[i]-mn[i]);
    cout << ans << endl;
	return 0;
}