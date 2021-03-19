//24
//abc129_a_airplane
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int p,q,r;
    cin >> p >> q >> r;
    int ans = p+q+r-max({p,q,r});
    cout << ans << endl;
    return 0;
}