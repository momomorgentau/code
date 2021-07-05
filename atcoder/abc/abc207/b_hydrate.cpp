//ABC_207_B
//Hydrate
//98
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ai = a;
    ll ci = 0;
    rep(i, int(1e7))
    {
        if (ai <= ci * d)
        {
            cout << i << endl;
            return 0;
        }
        ai += b;
        ci += c;
    }
    cout << -1 << endl;
    return 0;
}