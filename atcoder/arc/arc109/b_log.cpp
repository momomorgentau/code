//524
//arc109_b_log

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    ll wa, ac;
    wa = n + 1;
    ac = 0;

    ll llmax = sqrt(9223372036854775806);
    while (wa - ac > 1)
    {
        ll mid = (wa + ac) / 2;
        bool ok = false;
        if (mid < llmax)
        {
            ll t = mid * (1 + mid) / 2;
            if (t <= n + 1)
            {
                ok = true;
            }
        }

        if (ok) ac = mid;
        else wa = mid;

    }
    cout << n - ac + 1 << endl;
    return 0;
}




