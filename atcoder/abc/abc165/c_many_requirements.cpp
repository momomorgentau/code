//1136
//abc_165_c_many_requirements
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using P = pair<int,int>;

int n,m,q;
vector<int> a,b,c,d;
int ans = 0;
void dfs(vector<int> s)
{
    if(s.size() == n+1)
    {
        int now = 0;
        rep(i,q)
        {
            if(s[b[i]]-s[a[i]] == c[i]) now += d[i];
        }
        ans = max(ans,now);
        return;
    }

    s.emplace_back(s.back());
    while(s.back() <= m)
    {
        dfs(s);
        s.back()++;
    }

}

int main()
{
    cin >> n >> m >> q;
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    rep(i,q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    
    vector<int> A(1,1);
    dfs(A);
    cout << ans << endl;
    return 0;
}
