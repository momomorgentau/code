//004
//*2
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main()
{
    int h,w;
    cin >> h >> w;
    vector<vector<int>> g(h,vector<int> (w));
    rep(i,h)rep(j,w) cin >> g[i][j];

    vector<int> sum_h(h),sum_w(w);
    rep(i,h)rep(j,w)
    {
        sum_h[i] += g[i][j];
        sum_w[j] += g[i][j];
    }
    rep(i,h)
    {
        rep(j,w)
        {
            cout << sum_h[i]+sum_w[j]-g[i][j] << " "; 
        }
        cout << endl;
    }

    return 0;
} 