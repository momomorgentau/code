//769
//abc189_d_logocal_expresxion
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

ll dp[60+5][2];

int main()
{
    int n;
    cin >> n;
    dp[0][0] = 1;
    dp[0][1] = 1;
    rep(i,n)
    {
        string s; 
        cin >> s;
        if(s == "AND")
        {
            dp[i+1][0] = dp[i][0]*2 + dp[i][1];
            dp[i+1][1] = dp[i][1];
        }
        else 
        {
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][0] + dp[i][1]*2;
        }
    } 
    cout << dp[n][1] << endl;
	return 0;
}