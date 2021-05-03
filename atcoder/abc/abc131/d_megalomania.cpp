//588
//abc131_d_megalo_mania
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> ba(n);
    rep(i,n)
    {
        int a,b;
        cin >> a>>b;
        ba[i] = make_pair(b,a);
    }
    sort(ba.begin(),ba.end());
    bool ok = true;
    ll t = 0;
    rep(i,n)
    {
        int tb,ta;
        tie(tb,ta) = ba[i];
        t += ta;
        if(t > tb) ok = false;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}