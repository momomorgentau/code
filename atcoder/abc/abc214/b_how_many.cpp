//ABC_214_B
//How many?
//53
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, int>;
using T = tuple<int, int, int>;

int main()
{
    int s, t;
    cin >> s >> t;
    int ans = 0;
    rep(a, s + 1)
    {
        rep(b, s - a + 1)
        {
            rep(c, s - a - b + 1)
            {
                if (a * b * c <= t)++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}