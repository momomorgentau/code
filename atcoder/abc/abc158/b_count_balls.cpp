//123
//abc158_b_count_balls
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main()
{
    ll n,a,b;
    cin >> n >> a >> b;
    ll s = a + b;
    ll ans = 0;
    ans += (n / s) * a;
    ans += min(a,n%s);
    cout << ans << endl;
    return 0;
} 