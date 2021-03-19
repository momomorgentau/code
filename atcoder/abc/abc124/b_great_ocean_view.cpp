//67
//abc124_b_great_ocean
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int n;
    cin >> n;
    int mx = 0;
    int ans = 0;
    rep(i,n)
    {
        int h; cin >> h;
        if (mx <= h) ++ans;
        mx = max(mx,h);
    }
    cout << ans << endl;
    return 0;
}

