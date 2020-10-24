//180
//arc106f_106

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    ll n;
    cin >> n;
    int a = 0;
    int b = 0;
    ll ca = 1;
    ll cb = 1;

    while (1)
    {
        ++a;
        ca *= 3;
        cb = 1;
        b = 0;
        while (1)
        {
            ++b;
            cb *= 5;
            ll s = ca + cb;
            if (s == n)
            {
                cout << a << " " << b << endl;
                return 0;
            }
            if (s > n) break;
        }
        if (ca > n) break;

    }
    cout << -1 << endl;
    return 0;
}
