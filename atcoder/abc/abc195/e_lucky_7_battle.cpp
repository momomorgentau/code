//ABC195_E_Lucky_7_Battle
//1609
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int N = 2e5;
int dp[N+5][7];

int main()
{
    int n;
    string s,x;
    cin >> n >> s >> x;

    dp[n][0] = 1;
    for(int i = n-1;i>=0;--i)
    {
        rep(j,7)
        {
            int r1 = (10*j)%7;
            int r2 = (10*j+(s[i]-'0'))%7;
            if(x[i] == 'T') dp[i][j] = dp[i+1][r1] | dp[i+1][r2];
            else dp[i][j] = dp[i+1][r1] & dp[i+1][r2];
        }
    }
    if(dp[0][0] == 1) cout << "Takahashi"<< endl;
    else cout << "Aoki" << endl;
    return 0;
}


