//350
//abc128_b_guidebook
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int n;
    cin >> n;
    vector<tuple<string,int,int>> t;
    rep(i,n)
    {
        string s;
        int p;
        cin >> s >> p;
        t.emplace_back(s,-p,i+1);
    }
    sort(t.begin(),t.end());
    
    for(auto [a,b,c]:t) cout << c << endl;
    return 0;
}