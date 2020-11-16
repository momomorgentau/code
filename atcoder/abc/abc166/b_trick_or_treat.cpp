//43
//abc166b_trick_or_treat

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> snk(n,0);
    rep(i,k)
    {
        int d; cin >> d;
        rep(j,d)
        {
            int a; cin >> a;
            --a;
            ++snk[a];
        }
    }
    int ans = 0;
    for(auto i:snk) if(i==0) ++ans;
    cout << ans << endl;
    return 0;
}