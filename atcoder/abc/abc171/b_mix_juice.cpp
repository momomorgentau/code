#include<bits/stdc++.h>
//diff 5
//abc171_b_mix_juice
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main() 
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    sort(p.begin(), p.end());

    int ans = 0;
    rep(i, k) ans += p[i];

    cout << ans << endl;
    return 0;
}
