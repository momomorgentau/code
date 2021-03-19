//ABC_192_C_Kaprekar_Number
//105
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int g(int n,int f)
{
    vector<int> v;
    while (n > 0)
    {
        v.emplace_back(n%10);
        n /= 10;
    }
    if (f == 1) sort(v.begin(), v.end());
    else if (f == 2) sort(v.rbegin(), v.rend());
    int res = 0;
    int w = 1;
    for (auto vi : v)
    {
        res += vi * w;
        w *= 10;
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int ans = n;

    rep(i, k) ans = g(ans,1) - g(ans, 2);
    cout << ans << endl;

    return 0;
}