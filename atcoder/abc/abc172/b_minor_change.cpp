//diff 4
//abc 172 b Minor Change

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() 
{
    string s, t;
    cin >> s >> t;
    int l = s.length();
    int ans=0;
    rep(i, l) 
    {
        if (s[i] != t[i]) ++ans;
    }
    cout << ans << endl;
    return 0;
}
