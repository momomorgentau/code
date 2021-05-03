//ABC195_F_Coprime_Present
//2068
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
const int n = 20;
const ll bn = 1 << n;
ll dp[75][bn];

int main()
{
    ll a,b;
    cin >> a >> b;
    dp[0][0] = 1;
    int idx = 0;
    for(ll i = a; i<= b; ++i)
    {
        ll ai = i;
        ll si = 0;
        rep(j,n) if(ai%p[j]==0) si |= (1<<j);//(si+=(1<<j)と同じ)
        rep(s,bn)
        {
            //aiを選択しない
            dp[idx+1][s] += dp[idx][s];
            //aiを選択する（sにaiの素因数がない場合に可能）
            if((s&si) == 0) dp[idx+1][s|si] += dp[idx][s];
        }
        ++idx;
    }
    ll ans = 0;
    rep(s,bn) ans += dp[idx][s];
    cout << ans << endl;
    return 0;
}


