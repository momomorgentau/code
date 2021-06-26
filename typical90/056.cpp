//056
//Lucky_Bag
//*5
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int M = 1e5;
int dp[105][M*2 + 5];

int main() 
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, 105)rep(j, M+5) dp[i][j] = -1;
    dp[0][0] = 0;

    rep(i, n)rep(j, M)
    {
        if (dp[i][j] == -1) continue;
        dp[i + 1][j + a[i]] = 0;
        dp[i + 1][j + b[i]] = 1;


    }
    if (dp[n][s] == -1)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    string ans = "";
    int si = s;
    for (int i = n; i >= 1; --i)
    {
        if (dp[i][si] == 0)
        {
            ans += 'A';
            si = si - a[i-1];
        }
        else
        {
            ans += 'B';
            si = si - b[i-1];
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
 
    return 0;
}

