//859
//abc130d_enough_array

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main() 
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n+1);
    a[0] = 0;
    rep(i, n) cin >> a[i+1];

    ll s = 0;
    ll ans = 0;

    int j = 0;

    rep(i, n)
    {
        s -= a[i];
        
        while (1) 
        {
            if (s >= k) 
            {
                ans += n - (ll)j + 1;
                break;
            }
            if (j < n)++j;
            else break;
            s += a[j];
        }
        
    }
    cout << ans << endl;
    
    return 0;
}
