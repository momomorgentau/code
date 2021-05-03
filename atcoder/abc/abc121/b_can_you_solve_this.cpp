//ABC_121_B_Can_you_solve_this?
//80
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int n,m,c;
    cin >> n >> m >> c;
    vector<int> b(m);
    rep(i,m) cin >> b[i];
    int ans = 0;
    rep(i,n)
    {
        int now = c;
        rep(j,m)
        {
            int a; cin >> a;
            now += a*b[j];
        }
        if(now > 0) ++ans;
    }
    cout << ans << endl;
    return 0;
}