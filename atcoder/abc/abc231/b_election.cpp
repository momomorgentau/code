//----------------------------
//ABC 231 B
//Election
//39
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;


int main()
{
    int n;
    cin >> n;
    map<string, int> mp;
    rep(i, n)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    pair<string, int> ans = make_pair("",0);
    for (const auto& [k, v] : mp)
    {
        if (v > ans.second)
        {
            ans.first = k;
            ans.second = v;
        }
    }
    cout << ans.first << endl;
    return 0;
}

