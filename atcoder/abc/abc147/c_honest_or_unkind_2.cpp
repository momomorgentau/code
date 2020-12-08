//977
//abc147_c_honestOrUnkind
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
    vector<vector<P>> a(n);

    rep(i,n)
    {
        int ai; cin >> ai;
        rep(j,ai)
        {
            int xi,yi; cin >> xi >> yi;
            --xi;
            a[i].emplace_back(xi,yi);
        }
    }

    int ans = 0;

    rep(i,1<<n)
    {
        int bit = i;
        vector<bool> ta(n);
        int cnt = 0;
        rep(j,n)
        {
            if((bit>>j)&1)
            {
                ta[j] = true;
                ++cnt;
            } 
            else ta[j] = false;
        }

        bool ok = true;
        rep(j,n)
        {
            if(!ta[j]) continue;
            for(auto aj: a[j])
            {
                int ajx,ajy;
                tie(ajx,ajy) = aj;             
                if(ta[ajx] == ajy) continue;
                ok = false;
                break;               
            }
            if(!ok) break;
        }
        if(ok) ans = max(ans,cnt);
    }
    cout << ans << endl;

    return 0;
}