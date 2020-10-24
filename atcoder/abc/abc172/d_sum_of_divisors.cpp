//945
//abc172d_sum_of_divisors
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

ll solve1(int n)
{
    vector<int> c(n + 1);
    reps(i, 1, n + 1)
    {
        for (int j = i; j <= n; j += i) ++c[j];
    }
    ll ans = 0;
    reps(i, 1, n + 1)ans += ((ll)i * c[i]);
    return ans;
}

//faster
ll solve2(int n)
{
    ll ans = 0;
    reps(i, 1, n + 1)
    {
        ll m = n / i;
        ans += (ll)i * (m * (m + 1)) / 2;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << solve2(n) << endl;;
    return 0;
}
