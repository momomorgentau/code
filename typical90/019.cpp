//019
//*6
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
void chmin(int &a,int b) {a=min(a,b);}; 
int main()
{
    int n;
    cin >> n;
    int n2 = 2*n;
    vector<int> A(n2);
    rep(i,n2) cin >> A[i];
    vector<vector<int>> dp(n2+5,vector<int> (n2+5,1e9));
    rep(i,n2-1) dp[i][i+1] = abs(A[i]-A[i+1]);
    
    for(int i = 3; i<n2;i+=2)
    {
        for(int j = 0;j < n2-i;++j)
        {
            int l = j;
            int r = j + i;
            for(int k = l+1; k<r-1;++k)
            {
                chmin(dp[l][r],dp[l][k]+dp[k+1][r]);
            }
            chmin(dp[l][r],dp[l+1][r-1]+abs(A[l]-A[r]));
        }
    }
    cout << dp[0][n2-1] << endl;
    

    return 0;
}
/*
1 3 5 5 3 1
 2 2 0 2 2 
8 6 4 4 2 0
4 2 2 0
 4 2 0 

4*4
*/
