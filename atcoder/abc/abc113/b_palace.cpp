//ABC_113_B
//palace
//211
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n,t,a;
    cin >> n >> t >>a;
    t *= 1000;
    a *= 1000;
    int deg = 1e9;
    int ans = -1;
    rep(i,n)
    {
        int h;
        cin >> h;
        int now = abs(a-(t-h*6));
        if(deg <= now) continue; 
        ans = i+1;
        deg = now;
        
    }
    cout << ans << endl;
    

    return 0;
}