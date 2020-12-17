//16
//abc136_a_transfer
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = max(0, c - (a - b));
    cout << ans << endl;
    return 0;
}


