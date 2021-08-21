//ABC_210_A
//Cabbages
//19
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int n, a, x, y;
    cin >> n >> a >> x >> y;
    int ans = 0;
    rep(i, n)
    {
        if (i < a) ans += x;
        else ans += y;
    }
    cout << ans << endl;
    return 0;
}