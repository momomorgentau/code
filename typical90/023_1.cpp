//023
//*7
//task1
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

string g[4];
int main()
{
    int h,w;
    cin >> h >> w;
    rep(i,h) cin >> g[i];
    int ans = 0;
    rep(hw,1<<h*w)
    {
        vector<vector<int>> k(h,vector<int> (w));
        bool k_ok = true;
        rep(hwi,h*w)
        {
            bool bhw = hw & (1<<hwi);
            int hii = hwi / w;
            int wii = hwi % w;

            if(bhw)
            {
                k[hii][wii] = 1;
                if(g[hii][wii]=='#') k_ok = false;
            }
        }
        if(!k_ok) continue;

        bool ok = true;
        vector<int> dx = {-1,0,1,-1,1,-1,0,1};
        vector<int> dy = {-1,-1,-1,0,0,1,1,1};
        rep(i,h)rep(j,w)
        {
            if(k[i][j] != 1) continue;
            rep(l,8)
            {
                int nh = i+dy[l];
                int nw = j+dx[l];
                if(nh<0 || h<=nh)continue;
                if(nw<0 || w<=nw)continue;
                if(k[nh][nw])
                {
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
        }
        if(ok) ++ans;
    }
    cout << ans << endl;

    

    return 0;
}