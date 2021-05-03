//93
//abc131_bite_eating
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int n,l;
    cin >> n >> l;
    int sum = n*(l+l+n-1)/2;
    int mn = 1e9;
    rep(i,n)
    {
        int tm = l+i;
        if(abs(tm)<abs(mn)) mn = tm;
    }
    int ans = sum-mn;
    cout << ans << endl;
    return 0;
}