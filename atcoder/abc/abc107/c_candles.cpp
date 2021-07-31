//ABC_107_C
//Candles
//947
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    int ans = 1e9;
    reps(i,k-1,n)
    {
        int l = x[i-k+1];
        int r = x[i];
        ans = min(ans,abs(l)+r-l);
        ans = min(ans,abs(r)+r-l);
    }
    cout << ans << endl;
	return 0;
}