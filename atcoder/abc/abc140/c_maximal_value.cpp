//162
//abc140_c_maximal_value
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main() 
{   
    int n;
    cin >> n;
    vector<int> b(n-1);
    rep(i,n-1) cin >> b[i];
    int ans = b[0] + b.back();
    rep(i,n-2)
    {
        ans += min(b[i],b[i+1]);
    }
    cout << ans << endl;
    return 0;
}