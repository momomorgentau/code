//017
//*7
//task1
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;


int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> L(m),R(m);
    rep(i,m)
    {
        int l,r;
        cin >> l >> r;
        L[i] = l; R[i] = r;
        if(l > r) swap(L[i],R[i]);
    }
    int ans = 0;
    rep(i,m)
    {
        rep(j,m)
        {
            if(i==j) continue;
            if(L[i]<L[j] && L[j]<R[i])
            {
                if(R[i] < R[j] || R[j] < L[i]) ++ans;
            }
            else if(L[j]<L[i])
            {
                if(L[i] < R[j] && R[j] < R[i])++ans;
            }         
        }
    }
    ans /= 2;
    cout << ans << endl;
    return 0;
}
