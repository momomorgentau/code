//ABC_197_E_
//
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<P> cx;
    vector<ll> L = {0},R = {0};
    rep(i,n)
    {
        int c,x;
        cin >> x >> c;
        cx.emplace_back(c,x);
    }
    sort(cx.begin(),cx.end());
    map<int,bool> used;
    for(auto cxi:cx)
    {
        ll ci,xi;
        tie(ci,xi) = cxi;

        if(!used[ci])
        {
            L.emplace_back(xi);
            R.emplace_back(xi);
            used[ci] = true;
        } 
        else
        {
            int idx = L.size()-1;
            L[idx] = min(L[idx],xi);
            R[idx] = max(R[idx],xi);
        }
    }
    int s = L.size();
    vector<vector<ll>> dp(s+5, vector<ll> (2));
    dp[0][0] = 0;

    rep(i,s)
    {
        dp[i+1][0] = min(dp[i][0] + abs(L[i] - R[i+1]),
                         dp[i][1] + abs(R[i] - R[i+1]))
                         + abs(R[i+1]-L[i+1]);
        dp[i+1][1] = min(dp[i][0] + abs(L[i] - L[i+1]),
                         dp[i][1] + abs(R[i] - L[i+1]))
                         + abs(R[i+1]-L[i+1]);
    }
    ll ans = min(dp[s][0]+abs(L[s]),dp[s][1]+abs(R[s]));

    cout << ans << endl;
    return 0;
}