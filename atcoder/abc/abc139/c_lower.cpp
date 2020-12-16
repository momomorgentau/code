//152
//abc139_c_lower_power
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{   
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int ans = 0;
    int cnt = 0;
    rep(i,n-1)
    {
        if(h[i] >= h[i+1]) ++cnt;
        else cnt = 0;
        ans = max(ans,cnt);
    }
    cout << ans << endl;

    return 0;
}
