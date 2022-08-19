//Educational DP Contest J
//Sushi
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int M = 305;
int n;
double dp[M][M][M];
double dfs(int c1, int c2, int c3)
{
    if (dp[c1][c2][c3] > -1) return dp[c1][c2][c3];
    double z = (1 - (double)(n - (c1 + c2 + c3)) / n);
    double f = 1 / z;
    if (c1 > 0) f += dfs(c1 - 1, c2, c3) * c1 / n / z;
    if (c2 > 0) f += dfs(c1 + 1, c2 - 1, c3) * c2 / n / z;
    if (c3 > 0) f += dfs(c1, c2 + 1, c3 - 1) * c3 / n / z;
    dp[c1][c2][c3] = f;
    return f;
}
int main()
{
    cin >> n;
    vector<int> v(4, 0);
    rep(i, n)
    {
        int a; cin >> a;
        ++v[a];
    }
    rep(i, M)rep(j, M)rep(k, M) dp[i][j][k] = -10;
    dp[0][0][0] = 0;
    double ans = dfs(v[1], v[2], v[3]);
    printf("%.10f\n", ans);
    return 0;
}