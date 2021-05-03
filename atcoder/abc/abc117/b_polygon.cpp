//ABC_118_B_Polygon
//45
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n;
    cin >>n;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    int mx = *max_element(l.begin(),l.end());
    int s = 0;
    rep(i,n) s+=l[i];
    if(s-2*mx > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}