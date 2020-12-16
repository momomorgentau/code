//79
//abc140_b_buffet
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main() 
{    
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n-1);
    rep(i,n) cin >> a[i],--a[i];
    rep(i,n) cin >> b[i];
    rep(i,n-1) cin >> c[i];

    int ans = 0;
    rep(i,n)
    {
        ans += b[a[i]];
        if(i >= 1 && a[i]==a[i-1]+1) ans += c[a[i-1]];
    }
    cout << ans << endl;


    return 0;
}