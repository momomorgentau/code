//えびまのお誕生日コンテスト 2021 Day 1
//A
//
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll n;
ll dfs(ll a,ll b)
{
    ll num = n-10*a-8*b;
    if(num < 0||a>13||b>13) return (ll)1e18;
    if((num%26 == 0))
    {
        return a+b;
    }
    return min(dfs(a+1,b),dfs(a,b+1));
}
int main()
{
    cin >> n;
    //cout << dfs(0,0) << endl;
    int ans = 100100100;
    rep(i,26)rep(j,26)
    {
        if((n-8*i-10*j)%26==0)
        {
            ans = min(ans,i+j);
        }
    }
    cout << ans << endl;
    return 0;
}