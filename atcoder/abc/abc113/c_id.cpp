//ABC_113_C
//ID
//878
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n+1);
    vector<P> py; 

    rep(i,m)
    {
        int p,y;
        cin >> p >> y;
        v[p].emplace_back(y);
        py.emplace_back(p,y);
    }
    reps(i,1,n+1) sort(v[i].begin(),v[i].end());

    for(auto [p,y]:py)
    {
        string ans1,ans2;
        ans1 = to_string(p);
        ans2 = to_string(lower_bound(v[p].begin(),v[p].end(),y)-v[p].begin()+1);
        string add1,add2;
        while(ans1.size()+add1.size()<6) add1 +='0';
        while(ans2.size()+add2.size()<6) add2 +='0'; 
        printf("%s%s%s%s\n",add1.c_str(),ans1.c_str(),add2.c_str(),ans2.c_str());

    }



    return 0;
}