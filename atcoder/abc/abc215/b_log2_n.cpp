//ABC_215
//long2(N)
//68
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    ll n;
    cin >> n;
    ll t = 1;
    int ans = -1;
    while (t <= n)
    {
        t *= 2;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}