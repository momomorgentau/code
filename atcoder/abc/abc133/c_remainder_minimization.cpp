//592
//abc133_c_remainder_minimization
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

const int mod = 2019;

int main()
{
    int l, r;
    cin >> l >> r;
    int ans = 2020;
    for (ll i = l; i <= r; ++i)
    {
        vector<int> rem(2019);
        for (ll j = i + 1; j <= r; ++j)
        {
            int r = i * j % mod;
            if (rem[r]) break;
            ++rem[r];
            ans = min(ans, r);
        }
        if (ans == 0) break;
    }

    cout << ans << endl;

    return 0;
}

