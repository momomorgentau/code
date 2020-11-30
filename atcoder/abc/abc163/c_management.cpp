//201
//abc164_c_management
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using P = pair<int,int>;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,n-1)
    {
        int a; cin >> a;
        --a;
        v[a]++; 
    }
    for(auto nv : v) cout << nv << endl;
    return 0;
}