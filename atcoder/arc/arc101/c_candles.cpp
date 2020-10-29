//947
//arc101c candles
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

const int inf = 1e9;
int main() 
{
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    int np = 0;
    rep(i, n)
    {
        int tx; cin >> tx;
        if (tx < 0) ++np;
      
        x[i] = tx;
    }
    int ans = inf;

    //正のみ負のみの場合の対処
    int p1 = x[np] == 0;
    if(np+p1 >= k) ans = -x[np-k];
    if(n-np >= k) ans = x[np+k-1];

    int idx = 0;

    while (1)
    {
        int r = idx + k - 1;
        if (r >= n) break;
        int dl = x[idx];
        int dr = x[r];

        if (dl <= 0 && dr >= 0)
        {
            int ta = dr - dl;
            ta = min(ta - dl, ta + dr);
            ans = min(ans, ta);
        }

        ++idx;
    }
    cout << ans <<endl;
    return 0;
}