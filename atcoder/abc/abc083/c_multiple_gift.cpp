//392
//abc83_c_multiple_gift
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main()
{
    ll x,y;
    cin >> x >> y;
    int ans = 1;
    while(1)
    {
        if(x * 2 > y) break;
        x *= 2;
        ++ans;
    }
    cout << ans << endl;
    return 0;
} 