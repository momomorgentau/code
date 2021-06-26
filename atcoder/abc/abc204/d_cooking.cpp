//ABC_204_D
//Cooking
//832
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


const int M = 1e5;
int main()
{
    int n;
    cin >> n;
    vector<int> t(n);
    rep(i, n) cin >> t[i];
    int sum = 0;
    rep(i, n) sum += t[i];

    vector<int> dp(M+1005, 0);

    dp[0] = 1;
    rep(i, n)
    {
        for(int j=M; j>=0 ;--j)
        {
            dp[j + t[i]] = dp[j] | dp[j + t[i]];
        }
    }
    int ans = M;
    rep(i, M+1)
    {
        if (dp[i] == 1)
        {
            int a = i;
            int b = sum - i;
            ans = min(ans, max(a, b));
        }
    }
    cout << ans << endl;

    return 0;
}

