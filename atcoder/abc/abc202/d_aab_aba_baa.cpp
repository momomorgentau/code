//ABC_202_D
//aab_aba_baa
//966
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

ll perm(ll a, ll b)
{
    ll res = 1;
    for (ll i = 1; i <= a; ++i)
    {
        res *= b + i;
        res /= i;
    }
    return res;
}


int main()
{
    int a, b;
    ll k;
    cin >> a >> b >> k;

    ll now = 0;
    string ans = "";
    while (a+b > 0)
    {
        if (a == 0)
        {
            ans += 'b';
            --b;
            continue;
        }
        else if (b == 0)
        {
            ans += 'a';
            --a;
            continue;
        }
        ll next = perm((ll)a - 1, (ll)b);
        if (now + next < k)
        {
            --b;
            now += next;
            ans += 'b';
        }
        else if (now + next >= k)
        {
            --a;
            ans += 'a';
        }
    }
    cout << ans << endl;
    return 0;
}