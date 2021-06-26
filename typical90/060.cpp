//060
//Chimera
//*5
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;


void LIS_typical60(vector<int> &lis, vector<int>& ans, const vector<int> &v)
{
    for(int i=0;i<v.size();++i)
    {
        auto it = lower_bound(lis.begin(), lis.end(), v[i])-lis.begin();
        lis[it] = min(lis[it], v[i]);

        //本問題
        ans[i] = lower_bound(lis.begin(), lis.end(), INF) - lis.begin();

    }
}




int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    const int INF = 1e9;
    vector<int> f(n, 0), b(n, 0);
    vector<int> lis(n, INF);
    LIS_typical60(lis,f,a);
    reverse(a.begin(),a.end());
    rep(i, n) lis[i] = INF;
    LIS_typical60(lis, b, a);
    reverse(b.begin(), b.end());
    int ans = 0;
    rep(i, n) ans = max(ans,f[i]+b[i]-1);
    cout << ans << endl;
    return 0;
}