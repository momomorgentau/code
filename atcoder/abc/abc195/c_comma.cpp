//ABC195_C_Comma
//265
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve1()
{
    ll n;
    cin >> n;
    ll ans = 0;
    
    if(int(1e3) <= n && n< int(1e6))
    {
        ans += (n - int(1e3) + 1) * 1;
    }
    else if(int(1e6) <= n && n < int(1e9))
    {
        ans += (int(1e6)-1-int(1e3)+1)*1;
        ans += (n - int(1e6) + 1) * 2;
    }
    else if(int(1e9) <= n && n < ll(1e12))
    {
        ans += (int(1e6)-1-int(1e3)+1)*1;
        ans += (int(1e9)-1-int(1e6)+1)*2;
        ans += (n - int(1e9) + 1) * 3;
    }
    else if(ll(1e12) <= n && n < ll(1e15))
    {
        ans += (int(1e6)-1-int(1e3)+1)*1;
        ans += (int(1e9)-1-int(1e6)+1)*2;
        ans += (ll(1e12)-1-int(1e9)+1)*3;
        ans += (n - ll(1e12) + 1) * 4;
    }
    else if(n == ll(1e15))
    {
        ans += (int(1e6)-1-int(1e3)+1)*1;
        ans += (int(1e9)-1-int(1e6)+1)*2;
        ans += (ll(1e12)-1-int(1e9)+1)*3;
        ans += (ll(1e15)-1-ll(1e12)+1)*4;
        ans += 5;
    }
    cout << ans << endl;
}

void solve2()
{
    ll n;
    cin >> n;
    int comma = 1;
    ll ans = 0;
    ll d = 1000; 
    while(d <= ll(1e15))
    {
        if(d <= n)
        {
            if(n < d * 1000) ans += (n-d+1)*comma;
            else ans += (d*1000-1-d+1)*comma;
        }
        d *= 1000;
        ++comma;
    }
    cout << ans << endl;
}
void solve3()
{
    ll n;
    cin >> n;
    ll d = 1000;
    ll ans = 0;
    while(d <= ll(1e15))
    {
        ans += max(ll(0),n-d+1);
        d*= 1000;
    }
    cout << ans << endl;
}

int main()
{
    //solve1();
    //solve2();
    solve3();
    return 0;
}