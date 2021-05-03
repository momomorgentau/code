//008
//*4
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

const int mod = 1e9+7;
int c2i(char c)
{
    int res = -1;
    if(c == 'a') res = 1;
    else if(c == 't') res = 2;
    else if(c == 'c') res = 3;
    else if(c == 'o') res = 4;
    else if(c == 'd') res = 5;
    else if(c == 'e') res = 6;
    else if(c == 'r') res = 7;
    return res;
}
int main()
{
    int n;
    string s;
    cin >> n >> s;
    vector<ll> dp(8);
    dp[0] = 1;
    for(auto c:s)
    {
        int m = c2i(c);
        if(m == -1) continue;
        dp[m] = (dp[m]+dp[m-1]) % mod;
    }
    cout << dp[7] << endl;
    return 0;
}