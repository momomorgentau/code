//146
//arc108_a_sum_and_product

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;
using P = pair<int, int>;


int main()
{
    ll s, p;
    cin >> s >> p;

    int m = 0;
    bool ok;
    while (1)
    {
        ++m;
        ll t = m * (s - m);
        if (t == p)
        {
            ok = true;
            break;
        }
        else if (t > p || m == s)
        {
            ok = false;
            break;
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
