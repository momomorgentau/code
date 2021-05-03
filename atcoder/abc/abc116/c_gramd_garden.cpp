//ABC_116_C_Grand_Garden
//542
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n;
    cin >> n;
    vector<int> h(n+1);
    rep(i,n) cin >> h[i];
    h[n] = 0;
    int ans = 0;

    rep(minus,100)
    {
        rep(i,n)
        {
            if(h[i]-minus>0 && h[i+1]-minus<=0) ++ans;
        }

    }
    cout << ans << endl;

    return 0;
}