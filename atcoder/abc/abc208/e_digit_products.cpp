//ABC_208_E
//Digit Products
//2024
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using T = tuple<int, int, int>;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<int> d;
    while (n > 0)
    {
        d.emplace_back(n % 10);
        n /= 10;
    }
    int sz = d.size();
    vector<vector<map<ll, ll>>> dp(sz + 5, vector<map<ll, ll>>(2));
    ll x = 1;
    bool first = true;
    rep(i, sz)
    {
        int di = d[sz-i-1];

        //1桁目の処理
        if (first)
        {
            for (int next = 1; next < di; ++next)
            {
                dp[i + 1][0][next] += 1;
            }
            dp[i + 1][1][di] += 1;
            x *= di;
            first = false;
            continue;
        }
        //2桁目以降でその桁で初めて0以外の数を追加する
        else
        {
            for(int next = 1;next<10;++next)
            {
                dp[i + 1][0][next] += 1;
            }
        }
        //前の桁の時点で小さい
        for (auto [t, val] : dp[i][0])
        {
            rep(next, 10)
            {
                //val = dp[i][0][t]です。autoで定義してます。
                dp[i + 1][0][t * next] += val;
            }
        }
        //前の桁の時点では等しい
        //その時の掛け算は一意に決まる（x）
        //その桁で小さくなる
        rep(next, di)
        {
            dp[i + 1][0][x * next] += dp[i][1][x];
        }
        //その桁でも同じ
        dp[i + 1][1][x * di] += dp[i][1][x];
        
        x *= di;
    }
    ll ans = 0;
    for (auto [t, val] : dp[sz][0])
    {
        if (t <= k) ans += val;
    }
    if (x <= k) ++ans;
    cout << ans << endl;
    return 0;
}