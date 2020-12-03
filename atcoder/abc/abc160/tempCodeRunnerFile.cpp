//diff172
//abc_160_c_traveling_salesman_sround_lake
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;

const int inf = 1e9;

int main()
{
    int k,n;
    cin >> k >> n;
    vector<int> a(n);
    vector<int> da(n);

    rep(i,n) cin >> a[i];
    da[0] = k - a.back() - a[i];
    reps(i,1,n) da[i] = a[i] -a[i-1];
    int ans = inf;
    rep(i,n) ans = min(ans,k-da[i]);

    cout << ans << endl;
    return 0;
} 
