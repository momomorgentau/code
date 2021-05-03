//93
//abc129_b_balance
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>w(n);
    rep(i,n) cin >> w[i];
    int sum = 0;
    rep(i,n) sum+= w[i];
    int all = sum;
    int ans = 1001001;
    rep(i,n)
    {
        sum -= w[i];
        ans = min(ans,abs(all-sum - sum));
    }
    cout << ans << endl;

    return 0;
}