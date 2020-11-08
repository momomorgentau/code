//2
//abc167a_registration
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int ls, lt;
    ls = s.length();
    lt = t.length();
    string ans;
    if (s == t.substr(0, ls) && ls + 1 == lt) ans = "Yes";
    else ans = "No";

    cout << ans << endl;
    return 0;
}