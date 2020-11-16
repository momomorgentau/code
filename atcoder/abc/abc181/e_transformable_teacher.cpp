//1128
//abc181_e_transformable_teacher
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

const ll inf = 1e18;
int main() 
{
    int n, m;
    cin >> n >> m;
    int n2 = n / 2;
    vector<int> h(n);
    vector<int> w(m);

    rep(i, n) cin >> h[i];
    rep(i, m) cin >> w[i];
    sort(h.begin(), h.end());

    vector<int> d1((n+1)/2);
    vector<int> d2((n+1)/2);
    d1[0] = d2[0] = 0;
    rep(i, n2) 
    {
        int idx = i * 2;
        d1[i+1] = d1[i]+ h[idx+1] - h[idx];
        d2[i+1] = d2[i] + h[idx + 2] - h[idx + 1];
    }
    ll ans = inf;

    rep(i, m) 
    {
        int tw = w[i];
        auto it = lower_bound(h.begin(), h.end(), tw) - h.begin();
        if (it & 1) --it;

        ll a = (ll)d1[it/2] + d2[n/2] - d2[it/2] + abs(h[it]- tw);
        
        ans = min(ans,a);
    }
    cout << ans << endl;

    return 0;

}


