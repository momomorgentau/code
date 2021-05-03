//ABC_186_E_Throne
//1461
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;


//extended euclidean algorithm
tuple<long long, long long, long long> extgcd(long long a, long long b)
{
    if (b == 0) return { a,1,0 };
    long long g, x, y;
    tie(g,x,y) = extgcd(b, a % b);
    return { g,y,x - a / b * y };
}

int main() 
{
    int t;
    cin >> t;
    rep(i, t)
    {
        ll n, s, k;
        cin >> n >> s >> k;
        ll g, x, y;
        tie(g,x,y) = extgcd(k, n);
        if (s % g != 0)
        {
            cout << -1 << endl;
            continue;
        }
        n /= g;
        s /= g;
        k /= g;
        ll ans = (((-s * x)%n)+n)%n;
        cout << ans << endl;
    }
    return 0;
}