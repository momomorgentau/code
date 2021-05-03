//805
//abc128_c_switches
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<bool>> sw(m,vector<bool> (n));
    rep(i,m)
    {
        int k;
        cin >> k;
        rep(j,k) 
        {
            int s;
            cin >> s;
            sw[i][s-1] = true;
        }
    }
    vector<bool> p(m);
    rep(i,m) 
    {
      bool t; cin >> t;
      p[i] = t;
    }

    int ans = 0;

    rep(i,1<<n)
    {
        int ti = i;
        vector<bool> on(m);
        rep(j,n)
        {
            if(!(ti & 1<<j)) continue;
            
            rep(k,m)
            {
                if(sw[k][j]) on[k] = !on[k];
            }
        }
        bool ok = true;
        rep(i,m) if(p[i] != on[i]) ok = false;   
        ans += ok;
    }
    cout << ans << endl;
    return 0;
}