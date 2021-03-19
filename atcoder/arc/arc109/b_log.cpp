//524
//arc109_b_log

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;


void solve1()
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

void solve2()
{
    ll n;
    cin >> n;
    ll sn = 0;
    ll a = 0;
    int cnt = 0;
    while(1)
    {
        ++a;
        if(sn+a > n+1) break;
        sn += a;
        ++cnt;
    }
    cout << n - cnt + 1 << endl;
    return 0; 
}
int main()
{
    //solve1();
    solve2();
}


