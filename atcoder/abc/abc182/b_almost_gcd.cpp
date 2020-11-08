//72
//abc182b_almost_gcd
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int amax = 0;
    rep(i, n) amax = max(a[i], amax);

    int tmax = 0;
    int ans;
    reps(i, 2, amax + 1)
    {
        int ta = 0;
        rep(j, n) if (a[j] % i == 0) ++ta;

        if (tmax < ta)
        {
            tmax = ta;
            ans = i;

        }
    }

    cout << ans << endl;

    return 0;

}
