//ABC_107_B
//Grid Compression
//448
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int h,w;
    cin >> h >> w;
    vector<string> g(h);
    rep(i,h) cin >> g[i];
    vector<int> H(h),W(w);
    rep(i,h)
    {
        bool ok = true;
        rep(j,w)
        {
            if(g[i][j] == '#') ok = false;
        }
        if(ok) H[i] = 1;
    }
    rep(j,w)
    {
        bool ok = true;
        rep(i,h)
        {
            if(g[i][j] == '#') ok = false;
        }
        if(ok) W[j] = 1;
    } 
    rep(i,h)
    {
        if(H[i])continue;
        rep(j,w)
        {
            if(W[j])continue;
            cout << g[i][j]; 
        }
        cout << endl;
    }
	return 0;
}