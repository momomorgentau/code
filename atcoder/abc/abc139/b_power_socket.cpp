//123
//abc139_b_powersocket
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{   
    int a,b;
    cin >> a >> b;
    int ans = 0;
    int c = 1;
    while(c < b) 
    {
        c += a-1;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}
