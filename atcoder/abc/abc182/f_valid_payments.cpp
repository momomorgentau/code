//2102
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll = long long;



int main()
{
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<ll> d(n);
    for(int i=n-1; i>=0;--i)
    {
        d[i] = x / a[i];
        x %= a[i];
    }
    vector<ll> ud(n);//繰り上がるためには前桁が何個必要か
    rep(i,n-1) ud[i] = a[i+1]/a[i];
    ud[n-1] = 1e18;
    vector<vector<ll>> dp(n+1,vector<ll> (2));
    dp[0][0] = 1;
    rep(i,n)
    {
        //bj:before 下の桁からの繰り上がり
        //aj:after 上の桁への繰り上がり

        //y = x+z + bj -ud[i] *nj
        rep(bj,2)rep(aj,2)
        {
            //z = 0
            ll y = d[i] + bj -ud[i]*aj;
            if(0 <= y && y < ud[i]) dp[i+1][aj] += dp[i][bj];
            //y = 0
            ll z = -d[i]-bj+ud[i]*aj;
            if(0 < z && z < ud[i]) dp[i+1][aj] += dp[i][bj];

        }
    }
    cout << dp[n][0] << endl;
    return 0;


}

/*
y - x = z
x + z = y
  
x 2 0 1 9
z 1 0 5 2
y 3 0 7 1

z = 0
dp[i+1][0] = dp[i][0] + dp[i][1]
dp[0]

dp[i][j] // i桁目まで考えた時の繰り上がりがj 
*/
/*
3 9
1 5 10

3

5 198
1 5 10 50 100

5

4 44
1 4 20 100

4

9 11837029798
1 942454037 2827362111 19791534777 257289952101 771869856303 3859349281515 30874794252120 216123559764840

21
*/