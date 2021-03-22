//ARC_115_C_N_Coloring
//706
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll n;
    cin >> n;
    vector<int> ans(n+1,-1);
    ans[1] = 1;
    for(ll i = 1;i <= n; ++i)
    {
        if(ans[i] == -1) ans[i] = ans[i-1];
        if(i*2 <= n) ans[i*2] = ans[i]+1;
    }
    reps(i,1,n+1)cout << ans[i] << " ";
    cout << endl;
    return 0;
}

