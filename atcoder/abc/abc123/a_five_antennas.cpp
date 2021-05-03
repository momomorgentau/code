//ABC_123_A_Five_Antennas
//31
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int k;
    vector<int> v(5);
    rep(i,v.size()) cin >> v[i];
    cin >> k;
    bool ok = true;
    rep(i,v.size())rep(j,v.size())
    {
        if(i>=j)continue;
        if(v[j] - v[i] > k) ok = false;
    }
    vector<string> ans = {":(","Yay!"};
    cout << ans[ok] << endl;
    return 0;
}

