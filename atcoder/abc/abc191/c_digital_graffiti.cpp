//ABC_191_C_Digital_Graffiti
//1063
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int ans = 0;
    rep(i, h-1)rep(j, w-1)
    {
        int ti = i;
        int tj = j;
        int  cnt = 0;
        rep(tti, 2)rep(ttj, 2)
        {
            if (s[ti + tti][tj + ttj] == '#') ++cnt;
        }
        if (cnt & 1) ++ans;


    }
    cout << ans << endl;
    return 0;
}