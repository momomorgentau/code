//027
//*2
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;


int main()
{
    int n; cin >> n;
    set<string> st;
    map<string,bool> mp;
    rep(i,n)
    {
        string s;cin >> s;
        if(!mp[s]) cout << i+1 << endl;
        mp[s] = true;
    }
    return 0;
}