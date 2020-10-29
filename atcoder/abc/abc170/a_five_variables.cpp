//0
//abc170a_five_variables
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int ans;
    rep(i, 5)
    {
        int x; cin >> x;
        if (x == 0) ans = i + 1;
    }
    cout << ans << endl;
    return 0;
}