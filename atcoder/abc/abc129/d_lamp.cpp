//1103
//abc129_d_lamp
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<vector<int>> cal(h,vector<int> (w,-1));
    vector<vector<int>> row(h,vector<int> (w,-1));

    rep(i,h)
    {
        int j = 0;
        while(1)
        {
            if(s[i][j] == '#')
            {
                ++j;
                continue;
            }
            int cnt = 1;
            while(1)
            {
                if( &&s[i][j+cnt] == '.') ++cnt;
                else
                {
                    rep(k,cnt) hol[i][j] = cnt;
                    j += cnt;
                    break;
                }
            }
        }
        rep(j,w)
        {
            if(s[i][j] )
        }
    }


    return 0;
}